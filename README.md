# NarrativeCoding
#####final work Jan Everaert

##benodigdheden
- projector
- webcam
- witte tafel
- voldoende belichtte ruimte
- verlengkabel usb

##opstelling
1. bevestig de projector boven de tafel, men kan hiervoor gebruik maken van een spiegel, indien de projector dit ondersteund
2. hang de webcam aan of vlakbij de projector
3. zorg voor voldoende belichting in de ruimte

##voorbereiding##
Vooraleer je met het programma kan werken, is het belangrijk dat alle kaarten die je wenst te gebruiken uitgeprint en op maat geknipt zijn. het afknippen van de randen zorgt ervoor dat de detectie foutlozer en sneller gebeurd. Indien het mogelijk is de kaarten uit te printen op een steviger oppervlak, gaat men best voor deze oplossing, om makkelijk te plooien kaarten te voorkomen 

##instellingen##
 bij het opstarten van de applicatie, kunnen een aantal instellingen veranderd worden. de belangerijkste is deze van de webcam. Deze zorgen ervoor dat de webcam uitgelijnt staat met de projector. 
 
 de projector zal het beeld van de webcam in deze modus projecteren, bij een foutieve uitlijning zal een waaiereffect ontstaan. Gebruik de instellingen om het beeld zo goed mogelijk uit te lijnen. De rotatie van het beeld is hierin optioneel. Men gebruikt best de breedte-, hoogte- en positie instellingen.
 druk op de muis om verder te gaan met de applicatie. De settings zullen nu van het scherm verdwijnen.
 Volg de boodschappen op het scherm om verder te gaan
 
 In de linker onderhoek is een klein icoon te zien, waarmee de instellingen terug opgeroepen kunnen worden, bijvoorbeeld om het beeld verder aan te passen, of de webcam weer te geven
 
 ##belangrijke klassen
 ###User
 Deze klasse is de eigenlijke gebruiker. Dit staat in een apparte klasse om op langere termijn meerdere users per projectie toe te laten.
 
 ####states
 States zijn een belangrijk onderdeel van de logica. Dit geeft weer op welke manier de gebruiker met het programma interactie uitvoerd. Hieronder worden deze states opgelijst
 
##### -1. uitvoering van de settings. 
 Hier kan de gebruiker instellingen aanpassen, zoals het uitlijnen van de camera, of grootte van de te scannen tags
 
 ##### 0. Scan het boek
 In deze staat kiest de gebruiker het boek dat hij wil gebruiken. Bij het scannen van het boek wordt eerst nagegaan of dit bestaat, en indien dit het geval is word het corresponderende boek ingeladen, zodat alle codemomenten reeds opgeslagen zijn in het programma. 
 Bij het scannen van een correcte code gaat het programma automatisch naar de volgende state.
 
 ##### 1. Scan het codemoment
 De gebruiker is momenteel het boek aan het lezen. Indien deze op een codemoment stoot (aangegeven door een tag in het boek), kan hij dit scannen. Het programma detecteerd dit, en controlleerd of het gescannede codemoment effectief bestaat. De controle geeft hierna aan dat het programma naar een volgende state mag gaan
 
 ##### 2. Tutorial
 Soms is het nodig de gebruiker wat extra info aan te reiken. In deze stap is dit mogelijk. Na het doornemen van deze info kan de groene kaart gebruikt worden om door te gaan naar de volgende stap.
 
 ##### 3. Het codemoment
 
 
 
 
