#pragma once
namespace UI{
    static const char* ssid = "REM_POD";
    static const char* wpa = "Ghostly7";
    const char* TEMP_INPUT= "temp";
    const char* MAGx_INPUT = "magX";
    const char* MAGy_INPUT = "magY";
    const char* MAGz_INPUT = "magZ";
    const char* CALIBRATE = "Recalibrate";
    const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>GROUP 5 GHOST ALARM</title>
    <style>
        .dot-line{
            position: absolute;
            border-bottom: 10px dotted black;
            height: 80px;
        }
    </style>
</head>
<body>
    <h1>
        REM POD WEB INTERFACE
    </h1>
    <div style="float: right; width: 150px; height:  100px;" id="POD">
        <img src="pod.png" style="width: 100%; height: max-content;"></img>
    </div>
    <div style="width: 150px;height: 100px; float: right; margin-right: 700px;" id="Ghost">
        <img src="Ghost-Clipart-3.png" style="width: 100%; height: max-content;"></img>
    </div>
    <div class="dot-line"></div>
    </div>
    <div style="margin-bottom: 20px;" id="2">
        <form action="/get">
            <input type="number" name="temp">System Bias Temperature (&deg;C)</input>
            <input type="submit" value="Send">
        </form>
    </div>
    <div style="margin-bottom: 20px;">
        <form action="/get">
            <input type="number" name="magX">System Bias Magnetic Strength X (mT)</input>
            <input type="submit" value="Send">
        </form>
    </div>
    <div style="margin-bottom: 20px;">
        <form action="/get">
            <input type="number" name="magY">System Bias Magnetic Strength Y (mT)</input>
            <input type="submit" value="Send">
        </form>
    </div>
    <div style="margin-bottom: 20px;">
        <form action="/get" >
            <input type="number" name="magZ">System Bias Magnetic Strength Z (mT)</input>
            <input type="submit" value="Send">
        </form>
    </div>
    <div style="margin-bottom: 20px;">
        <form action="/get">
            <input type="submit" value="Recalibrate" style="font-weight: bold;" name="Recalibrate">
        </form>
    </div>
    <div style="background-color: gray; border-color: black; height: 300px;border-style: solid;">
        <h1 style="font-size: medium;" id="logOutput">Multi Mode Logger Output:</h1>
        <div style="height: 75%; overflow-y: auto;" id="logMessages">
            <!-----Add br tag after each log><!----->

        </div>
    </div>
    <div style="justify-content: center; margin-left: 25%;">
            Group Members: Cailin Bain, Ocean Bowling, Preston Beesley, Gabriel Campos, Nick McGarry, Ethan Poynter
    </div>
    <div style="margin-left: 43%; justify-content: center;">
        Special Thanks: Dr. Daniel Armentrout
    </div>
    <a href="https://github.com/nlive65/MAE-311-Project" style="margin-left: 50%;">Github</a>
    <script>
        var pod = document.getElementById('POD');
        var ghostImg = document.getElementById('Ghost');
        var dotLine = document.querySelector('.dot-line');
        var distance = pod.getBoundingClientRect().left - ghostImg.getBoundingClientRect().right;
        dotLine.style.width = distance + 'px';
        dotLine.style.left = ghostImg.getBoundingClientRect().right + 'px';
        if(distance < 10){
            alert("High Presence Detected");
        }
        var logMessages = document.getElementById("logMessages");
        var logSocket = new WebSocket('ws://' + window.location.hostname + ':81/');
        socket.onMessage = function (event){
            var message = event.data;
            var newLogEntry = document.createElement('div');
            newLogEntry.textContent = message;
            logMessages.appendChild(newLogEntry);
        };
    </script>
</body>
    )rawliteral";

}