import requests

response = requests.get('http://192.168.4.1')
print(response.text)