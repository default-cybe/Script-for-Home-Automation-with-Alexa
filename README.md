<div align="center">
      <h1>Script for Home Automation with Alexa</h1>
     </div>
<p align="center"> <a href="https://github.com/default-cybe" target="_blank"><img alt="" src="https://img.shields.io/badge/Website-EA4C89?style=normal&logo=dribbble&logoColor=white" style="vertical-align:center" /></a> <a href="https://twitter.com/default_yt_" target="_blank"><img alt="" src="https://img.shields.io/badge/Twitter-1DA1F2?style=normal&logo=twitter&logoColor=white" style="vertical-align:center" /></a> <a href="https://www.instagram.com/kaivalya_ahir" target="_blank"><img alt="" src="https://img.shields.io/badge/Instagram-E4405F?style=normal&logo=instagram&logoColor=white" style="vertical-align:center" /></a> <a href="https://www.linkedin.com/in/kaivalya-ahir/" target="_blank"><img alt="" src="https://img.shields.io/badge/LinkedIn-0077B5?style=normal&logo=linkedin&logoColor=white" style="vertical-align:center" /></a> </p>

# Description

An Arduino sketch that turns a NodeMCU (ESP8266) into an Alexa-controlled home automation hub. The board keeps a WebSocket open to the [Sinric](https://sinric.com) cloud service, and Sinric is the piece that passes your Alexa voice commands down to the board. Every device is tied to a GPIO pin, so saying "Alexa, turn on the fan" flips the relay on that pin and the appliance comes on.

I put this together to control ordinary, non-smart appliances around the house without buying a separate smart plug for each one.

# What it does

- Runs up to 8 devices off a single NodeMCU
- Reconnects on its own when the WiFi or the Sinric link drops
- Sends a heartbeat every few minutes so the cloud connection survives overnight, even when the ISP shuffles IPs around

# Hardware

What you'll need:

- A NodeMCU / ESP8266 board
- A relay module (up to 8 channels) to do the actual switching
- Whatever lights or appliances you want to control

Each device gets its own GPIO pin. Here's how the sketch wires them up:

| Device | GPIO |
| ------ | ---- |
| 1 | GPIO5 (D1) |
| 2 | GPIO4 (D2) |
| 3 | GPIO0 (D3) |
| 4 | GPIO2 (D4) |
| 5 | GPIO14 (D5) |
| 6 | GPIO12 (D6) |
| 7 | GPIO13 (D7) |
| 8 | GPIO15 (D8) |

One thing to keep in mind: the relays are active-LOW. Every pin starts out driven `HIGH` (off) at boot, and switching a device on pulls its pin `LOW`.

# Required Libraries

Grab these from the Arduino Library Manager, or build them from source:

- ESP8266 core for Arduino (this is what gives you `ESP8266WiFi` and `ESP8266WiFiMulti`)
- [WebSocketsClient (arduinoWebSockets)](https://github.com/Links2004/arduinoWebSockets)
- [ArduinoJson](https://github.com/bblanchon/ArduinoJson), the 5.x line, since that's what the Sinric examples were written against
- StreamString

# Setup

1. Make an account at [sinric.com](https://sinric.com) and add your devices there. Copy the API key from the dashboard, plus each device's ID.
2. Open `finalworkingforalexa.ino` in the Arduino IDE.
3. Drop your credentials in near the top of the sketch:

   ```cpp
   #define MyApiKey       "YOUR_API_KEY"        // Sinric API key from the dashboard
   #define MySSID         "YOUR_WIFI_SSID"      // your WiFi network name
   #define MyWifiPassword "YOUR_WIFI_PASSWORD"  // your WiFi password
   ```

4. Swap the placeholder device IDs in the `turnOn()` and `turnOff()` functions for the ones on your Sinric dashboard.
5. Pick your NodeMCU board and port, then upload.
6. Link the Sinric skill in the Alexa app and ask Alexa to discover devices.

# Tech Used

![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)

# License

MIT. See [LICENSE](LICENSE).
