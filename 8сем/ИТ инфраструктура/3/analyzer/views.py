from django.shortcuts import render
from .utils import analyze_ip, calculate_score, get_conclusion

def index(request):
    context = {}

    if request.method == "POST":
        ip = request.POST.get("ip")

        data, ports, dns = analyze_ip(ip)
        score = calculate_score(data)
        conclusion = get_conclusion(score)

        context = {
            "ip": ip,
            "data": data,
            "score": score,
            "conclusion": conclusion,
            "ports": ports,
            "dns": dns
        }

    return render(request, "index.html", context)
