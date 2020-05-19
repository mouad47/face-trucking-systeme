import cv2 


#importe la biblioteque de port serie "pyserial"
url = 'http://192.168.43.1:8080/video'
Video_Capture = cv2.VideoCapture(url)

while 1:    #la boucle est'infinie
     
     check,image = Video_Capture.read()  
      
     gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
     #convertir l'image en noire et blanc
     #blurred = cv2.GaussianBlur(gray, (5, 5), 0)
     ret,thresh = cv2.threshold(gray,55,255,cv2.THRESH_BINARY_INV)
     #faire le threchholding (deteter la defrence des couleurs) quantite du gray
     contours,h =cv2.findContours(thresh,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
     #tracer les contour 
     for cnt in contours:
         perimetre=cv2.arcLength(cnt,True)
         #calculer le perimetre de chaque contour, true verife que la contour est fermé
         approx = cv2.approxPolyDP(cnt,0.01*perimetre,True)
         #faire une approximation (tres compliqué) DP algorithms
        
    
         cv2.drawContours(image,[cnt],-1,(0,255,0),2)
     cv2.imshow('window',image)
     if cv2.waitKey(1)==ord('q'): 
         break
