import requests

response = requests.get('http://192.168.4.1/?variable=traslado1')
print(response.text)

#para cambiar de variable solamente poner traslado2