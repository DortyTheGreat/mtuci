import socket
import subprocess
import platform

COMMON_PORTS = [22, 80, 443]

def ping_ip(ip):
    param = "-n" if platform.system().lower() == "windows" else "-c"
    try:
        result = subprocess.run(
            ["ping", param, "1", ip],
            stdout=subprocess.DEVNULL
        )
        return result.returncode == 0
    except:
        return False

def resolve_dns(ip):
    try:
        return socket.gethostbyaddr(ip)[0]
    except:
        return None

def scan_ports(ip):
    open_ports = []
    for port in COMMON_PORTS:
        sock = socket.socket()
        sock.settimeout(0.5)
        try:
            sock.connect((ip, port))
            open_ports.append(port)
        except:
            pass
        finally:
            sock.close()
    return open_ports

def is_private_ip(ip):
    return ip.startswith("192.168.") or ip.startswith("10.") or ip.startswith("172.")

def analyze_ip(ip):
    alive = ping_ip(ip)
    network_score = 1.0 if alive else 0.2

    dns = resolve_dns(ip)
    dns_score = 1.0 if dns else 0.5

    ports = scan_ports(ip)
    port_score = 1.0 - (len(ports) * 0.2)

    private = is_private_ip(ip)
    reputation_score = 0.7 if private else 0.9

    data = {
        "network": [network_score],
        "reputation": [dns_score, reputation_score],
        "vulnerabilities": [port_score],
        "behavior": [0.8 if alive else 0.3]
    }

    return data, ports, dns

def calculate_score(data):
    weights = {
        "network": 0.3,
        "reputation": 0.2,
        "vulnerabilities": 0.3,
        "behavior": 0.2,
    }

    total = 0
    for key in data:
        avg = sum(data[key]) / len(data[key])
        total += avg * weights[key]

    return round(total * 100, 2)

def get_conclusion(score):
    if score >= 80:
        return "Высокий уровень безопасности."
    elif score >= 60:
        return "Средний уровень. Рекомендуется аудит."
    elif score >= 40:
        return "Низкий уровень. Усильте защиту."
    else:
        return "Критический уровень!"
