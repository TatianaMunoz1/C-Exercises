#INCLUDE<P16F628A.INC>
		__CONFIG 3F10

;DECLARACION DE ESPACIOS DE MEMORIA A USAR		
		CBLOCK	0X20
		D1
		D2
		D3
		D4
		AUX_W
		AUX_STATUS
        D1_N1
        D2_N1
        D3_N1
        AUX_D4
		D3_N2
		D1_N2
		D1_N3
		D2_N2
        D3_N3
        AUX_D8
		AUXILIAR9
		AUX_REST1
        AUX_NUM1
        AUX_NUM2
		CONT_AR	
		CONT_AR_2
		FLAG_M
		ENDC
		
;DECLARACION DE CONSTATNES
#DEFINE BTN_G1 	PORTA,6
#DEFINE BTN_G2 	PORTA,7
#DEFINE BTN_R 	PORTA,4
#DEFINE BTN_M 	PORTB,0

#DEFINE PIN_D1 	3
#DEFINE PIN_D2 	2
#DEFINE PIN_D3 	1
#DEFINE PIN_D4 	0

#DEFINE	CTRL_DISPLAY	PORTA
#DEFINE	APAGAR_DISPLAYS CLRF	PORTA

;DECLARACION DE MACROS

MOSTRAR	MACRO	DIGITO,PIN
		APAGAR_DISPLAYS
		MOVF	DIGITO,W
		CALL	TAB_DISPLAY
		MOVWF	PORTB
		BSF		CTRL_DISPLAY,PIN
		ENDM

;DECLARACION DE MEMORIA EEPROM

deciunoeeprom         equ  0x00
uniunoeeprom          equ  0x01
decidoseeprom         equ  0x02
unidoseeprom          equ  0x03
unidoseeprom          equ  0x03						





;INICIO DEL PROGRAMA		
INICIO		
		ORG		0X00
		GOTO	CONFI
		ORG		0X04		

;RUTINA DE INTERRUPCION
;DESBORDA EL TIMER CADA 15ms
;MUESTRA TODOS LOS DIGITOS DE ACUERDO A LAS VARIABLES D1:4

;GUARDA STATUS Y W EN VARIABLES AUXILIARES
		BCF		INTCON,T0IF
		BCF		INTCON,GIE		
		MOVWF	AUX_W
		MOVLW	STATUS
		MOVWF	AUX_STATUS

;MULTIPLEXADO DE DISPLAYS
		BTFSC	CTRL_DISPLAY,PIN_D1
		GOTO	MOSTRAR_D2			
		BTFSC	CTRL_DISPLAY,PIN_D2
		GOTO	MOSTRAR_D3
		BTFSC	CTRL_DISPLAY,PIN_D3
		GOTO	MOSTRAR_D4
		MOSTRAR	D1,PIN_D1
		GOTO 	FIN_T0I

MOSTRAR_D2
		MOSTRAR D2,PIN_D2
		GOTO 	FIN_T0I

MOSTRAR_D3
		MOSTRAR D3,PIN_D3
		GOTO 	FIN_T0I

MOSTRAR_D4
		MOSTRAR	D4,PIN_D4
		
FIN_T0I
;REINICIA TIMER Y RECUPERA STATUS Y W
		MOVLW	.198
		MOVWF	TMR0
		MOVF	AUX_STATUS,W
		MOVWF	STATUS
		MOVF	AUX_W,W
		RETFIE

;CONFIGURACION-------------------------------
		
CONFI
		MOVLW	0X07
		MOVWF	CMCON		;CMCON SE TIENE QUE ESTABLECER EN 7 PARA USAR TODO EL PORTA
		MOVLW	.198
		MOVWF	TMR0
		BSF		STATUS,RP0
		MOVLW	b'00000001'
		MOVWF	TRISB	
		MOVLW	b'11110000'
		MOVWF	TRISA
		BCF		OPTION_REG,T0CS
		BCF		OPTION_REG,PSA
		BSF		OPTION_REG,PS0
		BSF		OPTION_REG,PS1
		BSF		OPTION_REG,PS2
		BSF		INTCON,GIE
		BSF		INTCON,T0IE
		BCF		STATUS,RP0

;_________________________ -------------------______________________________
;________________________| RUTINA PRINCIPAL |_____________________________
;________________________| RUTINA PRINCIPAL | ______________________________
;________________________-------------------- ______________________________
;INCREMENTA DE 0 A (F) CADA DIGITO DEPENDIENDO QUE BOTON SE TOCA. 

		CLRF	PORTA
		CLRF	PORTB
		CLRF	D1
		CLRF	D2
		CLRF	D3	
		CLRF	D4
		CLRF	FLAG_M
BOTONES

		BTFSC	BTN_G1
		CALL	DEMORA_AR
		BTFSC	BTN_G1
		CALL	SUMAR

		BTFSC	BTN_G2
		CALL	DEMORA_AR
		BTFSC	BTN_G2
		CALL	RESTAR
	
		BTFSC	BTN_R
		CALL	DEMORA_AR
		BTFSC	BTN_R
		CALL	INICIO

		;BTFSC BTN_M
		;CALL DEMORA_AR
		;BTFSC BTN_M
		;GOTO CAMBIAR ;VER SI CONVIENE MAS USAR GOTO

		;GOTO 	BOTONES

;DEMORA-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DEMORA_AR
		MOVLW	.255
		MOVWF	CONT_AR
LOOP_AR
		MOVLW	.255
		MOVWF	CONT_AR_2
LOOP_AR_2
		DECFSZ	CONT_AR_2,1
		GOTO	LOOP_AR_2
		DECFSZ	CONT_AR,1
		GOTO	LOOP_AR
		RETURN
	;____________________________________________________________________________________________________________________________________________
	;_____________________________________________________CAMBIAR NUMERO_________________________________________________________________________
    ;____________________________________________________________________________________________________________________________________________
CAMBIAR
		BTFSS	FLAG_M, 0
		GOTO	CAMBIAR_A_N2
		GOTO	CAMBIAR_A_RESULTADO
		
		CAMBIAR_A_N2		
				INCF	FLAG_M,F	
				MOVF D1
				MOVWF D1_N1
				MOVF D2
			MOVWF D1_N2
				MOVF  D3
				MOVWF D1_N3
	
				CLRF D1
				CLRF D2	
				CLRF D3
				CLRF D4
				RETURN

		CAMBIAR_A_RESULTADO

				BTFSC	BTN_G1
				CALL	DEMORA_AR
				BTFSC	BTN_G1
				CALL	SUMAR

				BTFSC	BTN_G2
				CALL	DEMORA_AR
				BTFSC	BTN_G2
				CALL	RESTAR
		

				BTFSC BTN_M
				CALL DEMORA_AR
				BTFSC BTN_M
				CALL CAMBIAR
				

				SUBWF D1,D1_N1
				BTFSS STATUS,C
				MOVWF D3_N1
				CALL  TAB_DISPLAY_NEG
				SUBWF D2,D1_N2
				BTFSS STATUS,C
				MOVWF D3_N2
				CALL TAB_DISPLAY_NEG
				SUBWF D3,D1_N3
				BTFSS STATUS,C
				MOVWF D3_N3
			CALL TAB_DISPLAY_NEG
				RETURN



NEGATIVO
 		MOVWF D3_N3
		
 		GOTO TAB_DISPLAY_NEG
		RETURN

;___________________| SUBRUTINAS A MODIFICAR| ___________________________________________________________________________________________________________________
;___________________|      SUBRUTINAS       | ___________________________________
;___________________-------------------------____________________________________
SUMAR
		INCF	D3,1		;Incrementa el D3 en 1
		MOVF	D3,W		;Copia el valor de D3 a W
		XORLW	.16				;XOR con 16. inncrementa hasta 16
		BTFSS	STATUS,Z		;Si llega a 16, salta
		GOTO 	SALTEO_S		;RUTINA
		INCF 	D4,1			; Incrementa D4 a 1
		MOVF	D4,W			;Copia D4 en w
		CLRF	D3				;Borra D3
		XORLW	.16				;XOR con 16
		BTFSS	STATUS,Z		;Si llega a 16, D4, salta la bandera(Status,Z) en 1 (Compara 16 de D3 con el xor)
		GOTO 	SALTEO_S		;Rutina
		INCF	D2,1			;Incrementa D2 a 1
		CLRF	D4				;borra D4
SALTEO_S
		RETURN

RESTAR							
		DECF	D3,1
		MOVF	D3,W
		XORLW	.0	
		BTFSS	STATUS,Z		
		GOTO 	SALTEO_R
		MOVLW	0x0F
		MOVWF	D3
		DECF 	D4,1
		MOVF	D4,W
		XORLW	.0
		BTFSS	STATUS,Z		
		GOTO 	SALTEO_R
		DECF	D2,1
		MOVLW	0x0F
		MOVWF	D4
SALTEO_R
		RETURN
;_____________________-----------___________________________________
;_____________________| DISPLAY |___________________________________
;_____________________-----------___________________________________

				
;DISPLAY

;RB1->SEG A
;RB2->SEG B 
;RB3->SEG C
;RB4->SEG D
;RB5->SEG E 
;RB6->SEG F
;RB7->SEG G

TAB_DISPLAY
		ADDWF	PCL,1
		
		retlw		b'01111110'			;0
		retlw		b'00001100' 		;1
		retlw		b'10110110'			;2
		retlw		b'10011110'			;3
		retlw		b'11001100'			;4
		retlw		b'11011010'			;5
		retlw		b'11111010'			;6
		retlw		b'00001110'			;7
		retlw		b'11111110'			;8
		retlw		b'11011110'			;9
		retlw		b'11101110'			;A
		retlw		b'11111000'			;B
		retlw		b'01110010'			;C
		retlw		b'10111100'			;D
		retlw		b'11110010'			;E
		retlw		b'11100010'			;F

TAB_DISPLAY_NEG
		ADDWF 	PCL,4
		retlw 	b'00000010' ;-

END