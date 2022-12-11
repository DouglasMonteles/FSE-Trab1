import RPi.GPIO as GPIO

from time import sleep

leds = [18]

GPIO.setmode(GPIO.BCM)
GPIO.setup(leds, GPIO.OUT)

def main():
  led18_status = GPIO.input(18)
  print(f'Estado do LED: {led18_status}')
  
  if led18_status == 0:
    GPIO.output(leds, GPIO.HIGH)
  else:
    GPIO.output(leds, GPIO.LOW)

  print(f'Estado do LED: {led18_status}')

main()