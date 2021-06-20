# Description
Dit project heeft als onderwerp steganografie, dit is vergelijkbaar met cryptografie. Maar in tegenstelling tot de data onleesbaar maken voor iemand zonder een sleutel, is het doel van steganografie het feit verbergen dat er geheime data aanwezig is.

De vorm van stenografie waar dit project om draait is steganografie toegepast op afbeeldingen. Door data te overschrijven op lagere bits van de originele afbeelding, kan data verstopt worden. Deze data kan vervolgens weer uitgelezen worden en worden gescheiden van de verstopte data.

# Results
## Original Image
<div style="text-align:center"><img alt="Original Image" src="./img/original.jpg"/></div>

## Encode Using 1 Bit
<div style="text-align:center"><img alt="1 Bit Encode Image" src="./img/1bitEncode.bmp"/></div>

## Encode Using 6 Bits
<div style="text-align:center"><img alt="6 Bit Encode Image" src="./img/6bitEncode.bmp"/></div>

# Build
```
make all
```

# Features
- [X] Encode 
- [ ] Decode
- [ ] Supported filetypes:
    - [X] bitmap
    - [ ] png
    - [ ] jpg
