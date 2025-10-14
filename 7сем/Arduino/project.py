import telebot
import serial
import time

bot = telebot.TeleBot("")
arduino = serial.Serial('COM4', 9600, timeout=1)

@bot.message_handler(commands=['start'])
def start_game(message):
    bot.reply_to(message, "Игра началась! Смотрите на экран Arduino.")
    arduino.write(b'START\n')

    while True:
        line = arduino.readline().decode().strip()
        if line.startswith("RESULT:"):
            data = line.split(":")[1]
            wins, time_spent = data.split(",")
            bot.send_message(message.chat.id, f"Результат:\nПобед: {wins}\nВремя: {time_spent} сек")
            break
        time.sleep(0.5)

bot.polling()
