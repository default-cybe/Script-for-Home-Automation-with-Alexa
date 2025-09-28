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

