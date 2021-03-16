Formato de los paquetes para la comunicación serial con el sensor:
_________________________________________________________________________________________________________________________________________
    
1) Cabecera: FINGERPRINT_STARTCODE 0xEF01 (Enviar con el byte "high" primero)

2) Dirección del sensor: (Por defecto es 0xFFFFFFFF, enviar con el byte "high" primero)

3) Tipo de paquete:

   FINGERPRINT_COMMANDPACKET 0x1
   FINGERPRINT_DATAPACKET 0x2
   FINGERPRINT_ACKPACKET 0x7
   FINGERPRINT_ENDDATAPACKET 0x8

4) Longitud de los datos a enviar (hasta 256 bytes, enviar con el byte "high" primero):
   
   Si se envía un comando, se cuenta la longitud en bytes del paquete que contiene la instrucción mas 2 bytes para el "checksum",
   Si se envian datos, se cuenta la longitud en bytes del paquete de datos mas 2 bytes del checksum

5) Sección de datos: Pueden ser datos o un comando

6) CHECKSUM: The arithmetic sum of package identifier, package length and
             all package contens. Overflowing bits are omitted. high byte is
             transferred first 


FINGERPRINT_TIMEOUT 0xFF
FINGERPRINT_BADPACKET 0xFE

_________________________________________________________________________________________________________________________________________
Instrucciones:
FINGERPRINT_GETIMAGE 0x01
FINGERPRINT_IMAGE2TZ 0x02
FINGERPRINT_REGMODEL 0x05
FINGERPRINT_STORE 0x06
FINGERPRINT_LOAD 0x07
FINGERPRINT_UPLOAD 0x08
FINGERPRINT_DELETE 0x0C
FINGERPRINT_EMPTY 0x0D
FINGERPRINT_SETPASSWORD 0x12
FINGERPRINT_VERIFYPASSWORD 0x13
FINGERPRINT_HISPEEDSEARCH 0x1B
FINGERPRINT_TEMPLATECOUNT 0x1D
_________________________________________________________________________________________________________________________________________

