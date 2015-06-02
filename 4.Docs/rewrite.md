#abstract
#inleiding
De inspiratie voor dit onderzoek komt oorspronkelijk van één van de installaties op het Brusselse evenement "Nuit Blanche" (referentie en toelichten). Eén van de docenten liet een video zien waarin een connectie werd gemaakt tussen fysieke componenten en een projectie. In het gesprek dat volgde werd hier al snel een educatief doel aan gekoppeld. Fysieke componenten, een systeem om zogenaamde tags uit te lezen en te volgen, en een narratief. Het doel van het project: kinderen zin geven in programmeren en hen de eerste beginselen ervan bijbrengen.
Kinderen krijgen in dit project een verhaal aangeboden, in de vorm van een boek. Bepaalde pagina’s zijn leeggelaten. Op deze pagina is het de bedoeling dat het kind een stukje code legt om het hoofdpersonage verder te helpen, en zo het verhaal te laten verdergaan.
Doorheen de maanden is dit project sterk geëvolueerd. Zo heeft vooral het projectieoppervlak vele vormen gekend, van een tafeloppervlak naar een fysiek boek. Ook zijn de codeblocks (kleine componenten die de kinderen moeten inzetten om een doel te bereiken) van een plexiglazen blokje naar een speelkaartformaat gegaan.
Ik kreeg bij dit project hulp van een aantal personen, Waaronder mijn ouders, Wouter Van Den Broeck, Pieter Feys, Zach Lieberman, en Beyond.io.


In dit verslag beschrijf ik eerst de onderzoeksvraag. Daarna ga ik dieper in op Programmeren en de achterliggende denkvormen. In het derde deel bespreek ik de rol van een narratief in dit onderzoek. Het laatste deel beschrijft de opbouw van de code. 
#de onderzoeksvraag
###probleemschets
Er zijn reeds een aantal applicaties met het doel kinderen te leren programmeren. Dit gebeurt vaak in de vorm van een spel of kleine opdrachten. Deze applicaties missen helaas vaak een doel, soms komt het kind tot het ontwikkelen van een klein spel, maar dit blijft motivationeel beperkt.Een narratief kan ervoor zorgen dat kinderen langer gemotiveerd zijn, en minder snel afhaken omdat opdrachten op elkaar beginnen lijken. In deze applicaties worden verschillende programmeer onderdelen ook duidelijk één voor één aangeboden, in plaats van dit op een minder opvallende manier te doen (ik begrijp niet goed wat je bedoelt, moet het opvallen of juist niet en spreek je nu over jouw applicatie of over de andere?). Elke opdracht is ook verschillend van de vorige. Het kind doorloopt dus een aantal opdrachten, en weet na de laatste opdracht elk onderdeel correct te gebruiken. Het doel van het narratief is deze onderdelen aan elkaar te binden, zodat het geheel een grote opdracht wordt, zonder het kind "opdrachten" op te leggen.

###afbakening
De doelgroep van dit project ligt vooral tussen 8 en 12. Dit is een leeftijdsklasse waarin lezen vaak niet veel moeite meer vraagt, en de focus dus kan liggen op het schrijven van de code.

###doel van het onderzoek
Het onderzoek dient duidelijk te maken of een narratief effectief kan bijdragen aan een leukere leerervaring. Dit via een hands-on ervaring, en een empathische band met het hoofdpersonage van het verhaal. Het resultaat van dit onderzoek zal ook een POC (proof of concept) bevatten in de vorm van een applicatie die een extra dimensie geeft aan een verhaal, en het toestaat meerdere verhalen met dezelfde applicatie te kunnen gebruiken.
###onderzoeksvragen
####centrale vraag
Hoe kunnen we kinderen aanzetten tot coderen in een narratieve omgeving, en aan welke voorwaarden moet de digitale omgeving voloen om succesvol te zijn.
succesvol betekend in deze context het motiveren van de leerlingen, en het aanbieden van een specifiek doel waarnaar gestreefd kan worden. 
####deelvragen
De onderzoeksvragen laten zich indelen in een aantal categorieën. De eerste categorie bevat vooral vragen omtrent het leerproces van het kind, en welke elementen bij kunnen dragen aan een betere, leukere leerervaring. Het gaat hier dan vooral over de volgende vragen:

 * heeft handelend leren een positieve invloed, en hoe kan dit geïntegreerd worden in dit project
 * heeft empathie effect op leren en hoe werkt dat dan
 * leren in klasverband; welke randvoorwaarden hangen hieraan vast om effectief te zijn
Verder wordt het aanleren van programmeren aan kinderen in vraag gesteld.
 * waarom zou je kinderen leren programmeren
 * welke invloed heeft programmeren op kinderen
 * hoe kan dit technisch gerealiseerd worden
 
Welke eerste basiselementen van programmeren kunnen bij jonge kinderen aangeleerd worden
Naarmate het onderzoek vorderde, kwamen een aantal andere onderzoeksvragen aan bod. Deze gaan vooral over de functionaliteit van het programma, maar eveneens over de interactie die het programma aanbiedt tegenover de gebruiker

 * welke software en hulpmiddelen zijn reeds beschikbaar



###onderzoeksresultaat
Het vooropgestelde resultaat zal een verhaal bevatten, dat op bepaalde momenten het kind zal vragen een stukje te programmeren alvorens verder te gaan met het verhaal. Dit proces wordt ondersteund met een projectie en de nodige tips. Het aantal stukjes code dat hiervoor gebruikt kunnen worden zal in dit onderzoek beperkt worden. Het programma zal gebruik maken van empathie via narratieve elementen en andere technieken om het kind te motiveren.
#onderzoek
Ook hier een inleiding schrijven over wat je hier behandelt en in welke volgorde
##1. Waarom leren programmeren op jonge leeftijd?
In 2014 gaf de EU (www.eun.org)een rapport uit onder de titel 'computing our future' dat het integreren van programmeren in het lager onderwijs bespreekt. Het gaat hier vooral over landen die dit reeds doen (zoals Estland) maar eveneens over landen die dit van plan zijn in de nabije toekomst (waaronder België). Ook het nut van programmeren in een schoolomgeving wordt besproken met het oog op de toekomst van zowel de economie (meer programmeurs), maar belangrijker nog, met het oog op de ontwikkeling van het kind. Ik zou hier enkele zinnen uit het rapport overnemen, vb van p 10 wat ze willen aangeleerd zien. Je mag gewoon citeren, mits je de pagina vermeldt

Mitch Resnick (MIT, medeoprichter van Scratch) vergelijkt programmeren met schrijven; slechts weinig van de kinderen worden professioneel schrijver, maar kunnen schrijven is steeds handig. Hij vindt dat dit ook geldt voor code. Men moet niets computergerelateerd kiezen als beroep om de opgedane kennis te gebruiken. Programmeren stimuleert volgens Mitch het creatief denken, het systematisch redeneren en het samenwerken in teamverband. Verder kan het kind ideeën naar buiten brengen op deze manier. (Referentie)

Dit inzicht komt terug bij Derek Cabrera. Hij beschrijft in zijn TED-talk (referentie, vermeld het webadres) dat sommige kinderen het creatief denken verleerd hebben. Hij geeft hierbij het voorbeeld van Lego. Dit werd vroeger verkocht in dozen, zonder instructiehandleiding, terwijl deze momenteel vooral verkocht wordt in dozen waarmee men enkel de handleiding kan volgen, doordat de blokjes slechts één enkel model toelaten. volgens hem verleren kinderen hierdoor het creatief denkproces.

Tijdens dit onderzoek werd ik op het bestaan gewezen van 21t Century Skills, een organisatie die geregeld onderzoeken uitbrengt omtrent vernieuwing en integratie van deze skills in het onderwijs. 21st Century Skills stelt dat onze maatschappij van een industriële samenleving naar een kennis-samenleving veranderd is. Hun doel is het onderwijs aan te passen om beter aan te sluiten bij dat beeld van de 21ste eeuw. De Europese unie is hier reeds mee bezig, samen met bijvoorbeeld Unesco en een aantal Amerikaanse organisaties.  Deze discussie wordt helaas nog niet helemaal doorgetrokken naar het onderwijs. Deze skills zouden even belangrijk moeten zijn als wiskunde of Nederlands. Joke Voogt (bijzonder hoogleraar ICT & Curriculum aan de Faculteit der Maatschappij- en Gedragswetenschappen van de Universiteit van Amsterdam) is voorstander van een publiek debat die deze discussie opentrekt waarin ook ouders en studenten hun mening kunnen uiten.


###digitale samenleving
de digitalisering van de samenleving is enorm merkbaar in de tewerkstelling. Het aantal beroepen waarin productiewerk verricht wordt, daalt snel, en de beroepen waarin men creatief moet nadenken en probleemoplossend moet werken, zitten in de lift. In die laatste categorie is een degelijke IT-kennis interessant om praktische redenen:. Vooral voor communicatie, maar eveneens om de efficiëntie te verhogen. Daarom is het belangrijk dat we dit al van jongs af aan kunnen meegeven. Maar ook kan de logica van programmeren een oefenplaats zijn voor probleemoplossend denken.

###21st Century Skills
De term 21st Century Skills heeft betrekking op een geheel van vaardigheden die nodig zijn te functioneren in de huidige samenleving. Deze samenleving wordt onderverdeeld in een aantal groepen, "digital natives" en "digital immigrants". ( bron?)
De digital natives zijn in dit onderzoek de belangrijkste doelgroep. Zij zijn mee opgegroeid met de technologie, en ontdekken nieuwe ontwikkelingen en toepassingen, volledig onbevangen. Deze groep heeft weinig tot geen moeilijkheden met het gebruiken van nieuwe technologie, en zijn hier snel mee weg.
Tot de groep van "digital immigrants" behoren de volwassenen die de technologie hebben zien groeien. Sommigen zijn snel weg met vernieuwing, anderen twijfelen eerder alvorens deze te omarmen. Ook deze groep gebruikers leert omgaan met de nieuwere technologieën, maar hebben soms meer moeite deze vlot te integreren.
Het grote verschil tussen deze twee groepen is het gemak waarmee men overschakelt. Dit is vooral merkbaar in de manier van interactie. Terwijl de immigrants vooral vasthouden aan mail en formelere communicatie (ook face-to-face), maakt de groep van digital natives gebruik van sociale media zoals whats-app en facebook, en schakelt zeer snel over wanneer een nieuwe vorm beschikbaar is (vb: snapchat).
21st Century Skills worden onderverdeeld in een aantal vaardigheden. Deze worden vaak ondersteund door een degelijk gebruik van ICT. We spreken hier bijvoorbeeld over vaardigheden zoals:

 * samenwerking
 * kennisconstructie
 * ICT gebruik voor leren
 * probleemoplossend denken en creativiteit
 * planmatig werken
 
De nadruk in dit onderzoek zal liggen op het probleemoplossend denken en creativiteit. Dit omdat deze vaardigheid gestimuleerd wordt door programmeeractiviteiten en de denkwijze die hiermee gepaard gaat.

##2. Aan welke voorwaarden voldoet een krachtige leeromgeving

Met een krachtige leeromgeving bedoelen we een leeromgeving die participatie, betekenisgericht leren, levensechte contexten en zelfsturing mogelijk maken. Een dergelijke leeromgeving draagt bij tot de kwaliteitsverbetering van het onderwijsaanbod en tot de verhoging van het leerrendement bij alle leerlingen. (http://www.steunpuntdiversiteitenleren.be/nl/themas/krachtige-leeromgeving)

Om de activiteit om kinderen te leren programmeren effectief te maken, moeten ze dus zelf kunnen handelen (participatie). In het project realiseren we een betekenisvolle context  via een narratief. Zelfsturing stimuleren we door de kinderen  zelf oplossingen voor het gestelde probleem te laten zoeken. Het narratief zelf zorgt voor een ontspannen staat waarin de leerling snel en efficient kan leren.

 Neurowetenschapper prof. C. Lafosse verwijst naar het belang van motorisch handelen in leersituaties. Via het manipuleren van concrete voorwerpen prikkelen we zenuwbanen die in onze hersenen verbindingen leggen waardoor we leren. (http://www.klasse.be/tvklasse/20627-Christophe-Lafosse-Het-GeTalenteerde-Brein#.VWoKSYZUeK0). In dit project koos ik dan ook niet voor aanklikken of toetsen op een scherm maar voor het concreet plaatsen van objecten in een gekozen volgorde. Dit werkt anders dan games of applicaties via het scherm.

##3. Programmeren en diens onderverdelingen

###Metacognitie
Metacognitie betekend “denken over denken”. Ht wil zeggen dat een kind of persoon zich bewust wordt van zijn denkproces 

 (metacognitief denken, dit is niet hetzelfde, metacognitie is denken over denken, je kan wel spreken over de ontwikkeling van executieve functies, het kunnen sturen van een denkproces zoals de oplossing vinden van een ongewoon probleem. Dit soort denken houdt in dat men gemakkelijk nieuwe problemen kan oplossen, en ongestructureerde problemen kan structureren en er iets zinvol mee kan doen. 

###Algoritmisch denken
Algoritmisch denken wordt door de EU omschreven als "de mogelijkheid een probleem op te lossen via een stap-voor-stap oplossing (algoritme), waarin deze bestaat uit een eindige set duidelijk gedefinieerde stappen". (Referentie!)
Dit soort denken wordt vaak gebruikt tijdens het programmeren. Het komt erop neer dat de programmeur (in dit geval ook de gebruiker) een probleem dient te verdelen in een set kleinere deelproblemen, om daarna deze deelproblemen te kunnen oplossen via een stappenplan. Men moet hierbij natuurlijk ook rekening houden met de beginsituatie en het einddoel.
Het aanleren van deze vaardigheid gebeurt reeds in bestaande programma's. Onder andere Scratch (referentie)leert dit aan door gebruik te maken van een serie uitdagingen die het kind moet doorlopen. Tijdens dit proces leert hij het probleem op te delen in kleine acties. Nadat de gebruiker alle stappen heeft doorlopen, kan deze aan de slag met alle blokjes die Scratch bevat, om zelf creaties te maken.
Scratch kan een opstap zijn naar programma's als java, visual basic of javascript, zonder de leerling al direct te confronteren met het zoeken naar bugs als komma's of aanhalingstekens. Dit kan namelijk een grote drempel vormen, omdat een programmeur veel tijd doorbrengt een code te debuggen. Het werken met voorgemaakte blokjes neemt deze drempel weg.

###programming
Men kan het natuurlijk niet hebben over programmeren zonder de meest pure vorm te bespreken. Programmeren kent vele definities. de volgende is diegene die de EU gebruikt in zijn rapport:referentie
“Het kunnen realiseren van een algoritme in machinetaal, de stappen die genomen zijn kunnen interpreteren, [...] het kunnen compileren, runnen en debuggen van een programma, alsook het kunnen identificeren en hergebruiken van designpatterns”
Dit soort programmeren heeft een stijle leercurve. Het duurt even vooraleer men een eigenlijke output heeft, en het aanleren van de syntax neemt de nodige tijd in beslag. Kinderen kunnen hierdoor gedemotiveerd geraken, en haken af als gevolg. Daarom wordt in dit project gebruik gemaakt van een abstractere vorm hiervan. Een vorm waarin de syntax niet zichtbaar is voor de gebruiker, en deze ook niet aan de nodige haakjes, komma's of punt-komma's moet denken.
Programmeren laat zich onderverdelen in een aantal categorieën.
algoritmisch denken herhaling Misschien eerst programmeren en dan algoritmisch denken?
dit omvat het programmeren zonder effectief code te schrijven. Enkel standaard acties zijn hierin opgenomen. Variabelen en andere structuren komen hierin niet aan bod. Het oplossen van een probleem (meestal het bereiken van een bepaalde plek op het speelveld) kan hier opgelost worden door een opeenvolging van stappen zoals "stap naar rechts", "stap naar boven", en meer van dit soort blokken. Zoals eerder vermeld is deze vorm zeer geschikt voor jonge kinderen. Ze kunnen hier snel mee aan de slag en zien zeer snel resultaat. Dit is een ideale manier om snel en duidelijk een eerste probleem onder te verdelen in kleine stappen, en de drempel naar het volgende niveau is zeer laag. Voor ouderen is dit echter niet heel uitdagend, omdat de gelijkheid met het volgende level vaak te groot is en het als bandwerk aanvoelt.
####metaforisch programmeren
In deze stap (niet noodzakelijk in deze volgorde) komen de eerste programmeer structuren naar boven. Kinderen en volwassenen maken kennis met een "for loop", en een "if else" structuur. Ook variabelen komen hier aan bod. De gemakkelijkste manier om deze vorm te gebruiken is door de code onder te verdelen in kant en klare blokjes. Deze kan de gebruiker dan aaneenschakelen en een groter geheel vormen. In veel applicaties kan deze vorm voorgesteld worden als een efficiënter alternatief voor algoritmisch denken.
####flow programming
Flow programming wordt voorgesteld in programma's zoals pure data. De gebruiker verbindt blokjes die een actie of voorwaarde voorstellen met elkaar, om zo het programma uit te voeren. Deze vorm laat echter slechts moeilijk de implementatie van programmeer structuren toe.
####programming
Dit is de meest bekende vorm van programmeren. In deze vorm is de syntax van groot belang, en vele programmeertalen maken gebruik van deze vorm van programmeren. De nadruk ligt in deze vorm op het correct aanroepen van de juiste functies, en er moet vooraf heel hard nagedacht worden over de manier van implementatie. Deze vorm neemt ook de nodige tijd in beslag.
####in conclusion
Programmeren leert het kind op een andere manier nadenken over een probleem. Het bevordert het opdelen van een groot probleem in kleinere deelproblemen, en vlotter naar een oplossing te zoeken. Het algoritmisch nadenken staat het kind ook toe bepaalde acties die herhaald moeten worden misschien efficiënter uit te voeren.

##4. storytelling
Om volledig te kunnen begrijpen wat een narratief kan betekenen voor een gebruiker, en hoe we dit kunnen gebruiken, moeten we natuurlijk eerst definiëren hoe een verhaal in elkaar zit.

###Evolutie van verhalen

We vertellen al verhalen sinds het begin van mensenheugenis, denk maar aan de rotstekeningen in Frankrijk. In die tijd werden verhalen vooral verteld, om geschiedenis door te geven, of fenomenen te verklaren. Met de komst van een geschreven taal zijn we deze verhalen ook beginnen neerschrijven. Het is echter pas sinds de uitvinding van de boekdrukkunst dat we deze in geschreven vorm ook beginnen verspreiden zijn. De tijd tussen deze eerste vooruitgangen spreidt zich echter over duizenden jaren. Pas met de komst van de film is het echt snel beginnen gaan. Na film kwam radio en tv, waarna computers en het internet het rijtje voegden om verhalen door te geven.
Elk van deze uitvindingen bracht met zich mee dat artiesten een nieuwe manier hadden om verhalen te vertellen, maar ook hun verhalen aan te passen naar het gebruikte medium. Denk maar aan de uitvinding van de stop-motion truck in de filmwereld, waarmee het plots mogelijk werd verhalen anders vorm te geven, en andere verhalen te vertellen. Acties moesten niet meer mogelijk zijn, men kon truckeren.
In 2005 kwam youtube uit. Dit is een van de grotere mijlpalen in het vertellen van verhalen. Het werd mogelijk voor iedereen met een camera (elk soort camera) eigen verhalen en films te verspreiden. Dit in combinatie met het goedkoper worden van de filmcamera en smartphones zorgt voor een enorme boost in het aantal en de kwaliteit van verspreide films, en dus ook verhalen.
Nieuwe technologie gaat ook vaak gepaard met een nieuwe vorm van verhaalvertelling. Denk maar aan Vines, één van de recentere vormen hiervan. een online platform waarin de gebruiker een luttele 7 seconden kreeg om zijn punt, of verhaal, in duidelijk te maken.

###Storytelling
Het vertellen van verhalen heeft geen echte regels. Eerder wegwijzers. Er zijn een aantal guidelines waar aan gedacht kan worden, maar die niet nodig zijn om het schrijven van verhaal tot een goed einde te brengen. Vaak zijn de verhalen die afwijken van deze regels eerder succesvol, omdat de lezer verrast wordt.


Kenmerken van een goed verhaal zijn (Tesselaar & 
Scheringa, 2009):

* het staat op zichzelf, heeft een begin, midden en eind;
* het is authentiek (waar);
* het heeft een hoofdpersoon die iets meemaakt (bijvoorbeeld de verteller), plotwendingen en andere narratieve (verhalende) elementen;
* het is persoonlijk;
* het roept emotie op of wordt met emotie verteld. 


###fundamentals of digital storytelling
Als we spreken over digital storytelling, bedoelen we vooral een verhaal dat ondersteund wordt door een extra laag, die vaak computergestuurd is. Die laag kan aanvullend zijn, zoals het gebruik van augmented reality in een boek. Hij kan echter ook de enige laag zijn die we zien. Dit is vaak het geval in games of films. De gebruiker ziet het verhaal slechts afgespeeld op zijn scherm, en heeft hierop niet veel invloed.
De focus mag niet enkel liggen op het medium, er moet ook gedacht worden aan de manier van interactie, aan de hoeveelheid ervan, of het aantal variabelen waar de lezer mee te werk kan gaan. Men neemt hier vaak het voorbeeld van games. Deze werken eveneens met een narratief, dat vaak de input van users nodig heeft om te vorderen. Omdat dit proces zeer persoonlijk is, is het moeilijk een algemeen beeld op te stellen van hoe deze input verloopt. De ervaring van de interactiviteit varieert van speler tot speler.
De meeste focus in dit stuk ligt op de interactiviteit tussen speler en narratief. (Het volgende stuk zou ik behouden voor de beschrijving van jouw werk)Ik ben lang uitgegaan van het idee het verhaal te laten variëren naarmate andere stukken code neergelegd werden, maar dit bracht met zich mee dat het fysieke boek meerdere delen moest bevatten. Naarmate de speler andere code neerlegde zou hem/haar meegedeeld worden door te gaan naar een bepaalde pagina, waar het verhaal dan een andere wending nam. Dit is mogelijk, maar is complex. Vooral omdat het verhaal dan via een boomstructuur verloopt, en verschillende zijverhalen moeten geschreven worden. (Het volgende deel is dan weer algemeen en zou ik hier laten)
Digitale verhalen (zoals games en interactive stories) hebben het voordeel abstracte onderwerpen meer toegankelijk te maken voor verscheidene doelgroepen. zo zijn er bijvoorbeeld veel youtube kanalen die gebruik maken van een narratief om ingewikkelde wetenschappelijke onderwerpen op een klare manier uit te leggen. Ze kunnen ook helpen leerstof aantrekkelijker te maken, en zo minder gemotiveerde studenten toch aan te zetten tot leren. Het gebruik van de creativiteit van de gebruiker en zijn diepere gedachten creëren een sterker gevoel van doel in het leren (Hull and Katz, 2006).

Het beste leren we uit eigen ervaring. Verhalen zijn daarvoor ideaal, ze zorgen ervoor dat onze hersenen op zoek gaan naar connectie en betekenis. OOk worden bepaalde neuronen in onze hersenen geactiveerd, waardoor het ijkt alsof we het zelf meemaken. Een goed verteld verhaal kan aanvoelen alsof we het zelf meegemaakt hebben. Het is voor ons brein ook gemakkelijker verbindingen te vormen bij het aanhoren van een verhaal of anekdote( Milton Erickson, of recenter: Brein@work, 2010; Reynolds, 2011). Een narratieve context voegt dus betekenis toe, en legt verbindingen in je hersenen naar contexten die je herkent, waardoor je het beter opneemt en dus beter leert. Leren is verbindingen leggen in de hersenen, en een betekenisvolle context helpt daarbij. 

Als we een verhaal aanhoren, zijn we zowel ontspannen als oplettend. Dit is een goede staat om nieuwe dingen te leren, en er een positieve ervaring aan te kopelen.

 (http://www.idealearninggroup.com/blog/the-role-of-stories-in-learning)


##slot

Verhalen kunnen dus een zeer belangrijke rol spelen in het leren van nieuwe informatie en skills. Zowel het verhaal als de staat waarin deze ons brengt dragen bij aan beter en efficienter leren.

##Narrative driven programming
###inleiding


###Doel van het project

Het project is ontworpen om kinderen op een leukere manier kennis te laten maken met algoritmes en de basis van programmeren. Dit op een narratieve manier, en een fysiek boek. Het gehele programma werkt als een platform waar schrijvers en leerkrachten zelf boeken kunnen invoeren. Het kind leest het boek, waardoor kinderen een empatische band crëren met het hoofdpersonage. Op een aantal momenten zal het boek dienen om een programmeermoment op te roepen. Dit gebeurd door het scannen van het boek. Daarna kan het kind met kaarten een stukje programmeren, en laten uitvoeren. Deze uitvoer wordt natuurlijk visueel weergegeven, waardoor de gebruiker fouten gemakkelijk kan opsporen. 

###rol van het verhaal

####doel van het verhaal in dit project

Eerder werdt al vermeld dat het verhaal dynamisch ingevoerd kan worden. Dit omdat een vast verhaal de mogelijkheden te hard beperkt. In mijn zoektocht naar een degelijk verhaal viel me op dat kinderen soms reeds in klasverban

####Zoektocht naar een narratief


###programmastructuur

####algemene structuur
Het programma werkt via een aantal fasen. Deze laten toe dat er toevoegingen kunnen gebeuren zonder te moeten zoeken in een ingewikkelde structuur van als-dan loops. Om de code duidelijk en gestructureerd te houden wordt er natuurlijk ook gewerkt met klassen. Niet alle klassen zullen in dit document uitgebreid besproken worden.
De interfaceklasse
Deze klasse neemt de visuele output voor zijn rekening. Het zorgt ervoor dat de gebruiker weet waar het boek gelegd moet worden om gescand te worden, of welke codeblokjes met elkaar verbonden zijn. Om dit overzichtelijk te houden heeft elke status een eigen functie.
Deze klasse is pas vrij laat toegevoegd, omdat de nood aan een uitgebreide visuele output mij pas duidelijk werd na een gesprek met Beyond.io. Deze output bestond al reeds maar werd vooral door de hoofdklasse afgehandeld.
De verhaalklasse
Deze klasse wordt pas aangeroepen als een nieuw boek gescand wordt. Indien dit zich voordoet haalt deze klasse de nodige bestanden uit een online file-structuur. Deze zal eveneens een foutmelding weergeven als het gescand boek niet herkend wordt. Eens deze bestanden opgeslagen zijn zal deze klasse dienen als een centrale verzamelplaats waar andere klassen informatie uit kunnen halen, zoals bijvoorbeeld de compilatieklasse en de visuele weergave van het desbetreffende level.

####De compilatieklasse
Deze klasse heeft een aantal zeer verschillende vormen ondergaan. Dit omdat de eigenlijke werking vrij ingewikkeld in elkaar zit. De klasse krijgt aanvankelijk een serie getallen door, die deze omzet in acties. Dit was natuurlijk een gemakkelijke functie, tot het gebruik van for-loops (herhaling van een aantal acties) in het blikveld terecht kwam. Hieronder wordt het gehele proces opgedeeld in een aantal stappen.
#####Stap 1
De eerste stap gebeurt reeds voor de gebruiker kaarten heeft neergelegd. In deze stap zal de compiler het speelveld opdelen in een aantal blokken. Sommige blokken zorgen ervoor dat de speler niet verder kan, anderen zijn zogenaamde valkuilen, waar de speler opnieuw moet beginnen indien hij deze raakt.
#####Stap 2
De speler heeft zijn kaarten gelegd, en heeft een groene kaart in de desbetreffende zone gelegd om duidelijk te maken dat hij zijn sequentie wil testen. De compiler zal hierop een eerste keer over de serie getallen lopen, om op zoek te gaan naar een for-loop. Indien deze tegengekomen wordt, zal hij de acties binnen deze loop herhalen. Het aantal herhalingen hangt af van wat de gebruiker ingegeven heeft.
#####Stap 3
Nadat alle speciale acties zijn omgezet in een lange serie afzonderlijke acties, zal deze klasse uitzoeken of de uitvoer mogelijk is. Omdat deze reeds weet waar de valkuilen en solide blokken zitten, kan deze stap voor stap nagaan of de speler een code heeft gelegd die lukt. Hij doet dit door actie voor actie uit te zoeken waar de speler staat, en of deze positie een gevolg heeft. Elke stap zal opgeslagen worden in een nieuwe Array (opeenvolging van acties).
#####Stap 4
Hierna (onafhankelijk van het resultaat van voorafgaande functie) zal de laatstgenoemde array uitgevoerd worden. Dit gebeurt traag, en stap voor stap, zodat de gebruiker kan volgen via de kaarten die hij reeds heeft neergelegd. Op deze manier kan de gebruiker ook terugvinden waar hij een fout heeft gemaakt. Terwijl deze acties worden uitgevoerd, wordt de kaart die overeenkomt met de actie aangeduid via de projectie.

####De tag recognition
Tags zijn snel herkenbare afbeeldingen die eruit zien als een vereenvoudiging van een QR code. Ze worden algemeen gebruikt om informatie door te geven aan het programma. Onder andere het overgaan naar een codemoment, maar eveneens de positie van blokken code worden via deze tags geregeld.
Deze tags hebben een cruciale rol in het geheel. Daarom moest dit stukje software bijzonder efficiënt kunnen lopen, en de nodige ID’s als output hebben. Ik ging natuurlijk eerst op zoek naar een soortgelijke plugin, die me verder zou helpen. De gevonden systemen waren helaas slechts in staat met eigen tags te werken. Het aanpassen om bijvoorbeeld enkel bepaalde kleuren te tracks, het beeld negatief te maken, of de positie in een bepaalde vorm weer te geven zou teveel tijd hebben genomen. Verder was het ook een bijzonder zware plugin, omdat deze heel het cameraveld analyseert. Ik besloot zelf een eigen plugin te schrijven die dit waar kon maken.
#####Versie een
Eerlijk is eerlijk, mijn eerste versie liep zo mogelijk nog minder efficiënt dan de eerder vermeldde plugin. Ik maakte gebruik van een systeem dat de volgende stappen onderneemt:

1. de vorige positie als centrum voor de huidige scan
2. 360 graden rond deze positie op verscheidene afstanden de kleur bepalen
3. indien het punt donker genoeg was, werd dit opgeslagen in een lijst.
4. De lijst wordt overlopen om het verste punt te bepalen.
5. tussen deze vier punten werd dan geïtereerd om de desbetreffende code te bepalen.
6. de rotatie werd opgeslagen in een object.


Natuurlijk namen al deze stappen bijzonder veel tijd in beslag. Ik moest dus op zoek naar een efficiëntere versie die dezelfde output kon geven.
#####Versie twee
Het probleem met deze eerste versie is dat deze het gehele oppervlak moet afzoeken naar een tag. Dit kon efficiënter. Ik besloot het probleem op te lossen door gebruik te maken van bepaalde scanvelden. Dit zijn kleine velden die geprojecteerd worden waarin een kaart gescand kan worden. Het programma moest in plaats van 1400\*900 dus nog maar 200\*200
#####Finale versie
Omdat ik toch al werkte met een beperkt oppervlak, leek het me onnodig vanuit het midden te beginnen scannen. Bij gevolg verliep de scan nu in een veel efficiëntere vorm. Elk quadrant wordt apart behandeld. Er werd van buitenaf naar binnen gescand, tot er een eerste donkere punt werd gedetecteerd. op dit moment wordt dit opgeslagen als verste hoek, en werd dit quadrant verder genegeerd. Deze actie alleen haalde de nodige processor kracht al met een 20tal percent naar beneden. Verder wordt slechts een scan uitgevoerd als de camera detecteerde dat de kleur van het veld drastisch veranderd was. 

##conclusions and further work

Verhalen hebben altijd een grote rol gespeeld in het aanleren van nieuwe technieken. Een narratief zorgt ervoor dat de gebruiker of lezer gemakkelijk


------
#todo

* dankwoord
* inleidingen
* conclusion
* 

###De sleutel tot een goed verhaal (volgens andrew stanton)
Het vertellen van een verhaal loopt gelijk aan het vertellen van een mop. Je weet op voorhand hoe het verhaal to stand zal komen, en hoe het zal aflopen. Alles moet leiden tot één uiteindelijk resultaat. Veelal is dit een doel van het hoofdpersonage. Soms is dit doel niet specifiek uitgesproken. Het kan dieper liggen dan waar het verhaal over gaat. Dit doel zorgt niet altijd voor de goede beslissing. De hoofdrol kan volledig de verkeerde richting uitgestuurd worden.
We kijken verhalen om te voelen, meevoelen met de protagonist. Volgens Andrew Stanton willen we ook vooral onszelf in de schoenen van de protagonist kunnen plaatsen. Verhalen laten ons dus toe gelijkheden tussen onszelf en anderen (in een andere tijd of ruimte) te kunnen voelen, of meemaken.
“there isn’t anyone you couldn’t learn to love, once you’ve heard their story”
Andrew spreekt in zijn talk ook grotendeels over “a promise worth your time”. Een belofte die aan het begin van het verhaal gemaakt worden en waar naartoe geleefd kan worden. Een belofte die de lezer belooft dat zijn tijd waardig besteed zal worden. Een van de meest gebruikte zinnen om dit te doen is “er was eens”. Andrew beschrijft het belang van deze belofte als een steentje, in een katapult. het katapulteert de lezer/luisteraar door het verhaal, tot aan het einde.
Lezers, luisteraars, of kijkers willen best werken voor hun verhaal. ze willen het alleen niet expliciet weten. Het voelt meer aan als een eigen werk als je zelf de gaten kan invullen, onbewust. Als voorbeeld kan Wall-E aangehaald worden. een film over een afvalrobot die achterblijft op een vervuilde planeet( pixar ). Wall-e kan niet praten, en dus moet het publiek zelf werken voor hun eten (uitspraak ).
quotes
“drama is anticipation mingled with uncertainty” “technology is as ambiguous as the air we breath” godfrey Reggio “work with technology that exists, not with the promises of tomorrow” tawny schlieski
“we zijn op een punt in digital storytelling waar we niet goed weten wat te vertellen, maar enthousiast zijn over de mogelijkheden.” dit was een situatie die voorkwam in het begin van film, waar mensen filmpjes animeerden waarin geen verhaal verteld wordt, maar vooral de effecten getoond werden.
work with tools of today, not with the promises of tomorrow


