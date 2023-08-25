import requests

var = 12345
url = 'http://192.168.4.1/?var=' + str(var)
response = requests.get(url)
print(response.text)

#para cambiar de variable solamente poner var2 en la variable NO CAMBIAR EL VAR DENTRO DE LAS COMILLAS SIMPLES AL LADO DEL URL DEL SERVIDOR NO SEAN BESTIAS