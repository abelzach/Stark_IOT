import edtls, json, time
from boltiot import Email, Bolt


mybolt = Bolt(edtls.API_KEY, edtls.DEVICE_ID)
mailer = Email(edtls.MAILGUN_API_KEY, edtls.SANDBOX_URL, edtls.SENDER_EMAIL, edtls.RECIPIENT_EMAIL)


print("Welcome to A_C_Stark_SSLS Traffic Density Analyser :)")



while True:
 response = mybolt.serialRead('10')
 data = json.loads(response)
 print("Current Count: " + str(data['value']))
 try:
  sensor_value = 0
  sensor_value = int(data['value'])
  if sensor_value > 0:
   print("Making request to Mailgun to send an email...")
   response = mailer.send_email("Stark_SSLS Daily TDR", "The Traffic Count for yesterday dusk till today dawn was: " + str(sensor_value))
   response_text = json.loads(response.text)
   print("Response received from Mailgun is: " + str(response_text['message']))
 except Exception as e:
   print("Error occured. Details below.")
   print(e)
 print("Reading data......")
 time.sleep(10)
