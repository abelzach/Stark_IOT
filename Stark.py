import boltiot, json, time, detls
from boltiot import Bolt, Sms


mybolt = Bolt(detls.API, detls.D_ID)


s = Sms(detls.SID, detls.Token, detls.T_No, detls.F_No)

print("Welcome to A_C_Stark_SSLS Traffic Density Analyser :)")

while True:
 response = mybolt.serialRead('10')
 data = json.loads(response)
 print(response)
 print("Current count: " +str(data['value']))
 try:
  s_val = int(data['value'])
  if s_val > 0:
   print("Traffic Count detected:" + str(s_val))
   print("Making request to send your SMS....")
   response = s.send_sms("Count of vehicles during the night: " + str(s_val))
   print("Response received: " + str(response))
   print("The status of your SMS request: " + str(response.status)) 
 except Exception as e:
  print("Sorry, an error occured. Details:")
  print(e)
 print("Waiting for next sensor reading....") 
 time.sleep(10)
