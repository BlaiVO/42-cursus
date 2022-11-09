fun main() {
    val paraules = arrayOf("PORTA", "COSTA", "BROMA", "ABANS", "COURE", "SORDA", "DIURN", "VIURE", "OSTRA", "MOURE", "LLOSA", "RENTA", "MENTA", "PINTA", "PRUNA", "PROSA", "TOCAT", "SALUT", "MANTA", "FORTA")
    val paraula = paraules.random()
    val verd = "\u001b[48;2;60;168;63m\u001B[1m\u001B[38;2;255;255;255m"
    val gris = "\u001b[48;2;120;124;126m\u001B[1m\u001B[38;2;255;255;255m"
    val groc = "\u001b[48;2;214;154;41m\u001B[1m\u001B[38;2;255;255;255m"
    val reset = "\u001b[0m"
    val Lvermell = "\u001b[38;2;255;0;0m"
    val vermell = "\u001b[48;2;255;0;0m\u001B[1m\u001B[38;2;255;255;255m"
    val negre = "\u001b[48;2;211;214;218m\u001B[1m\u001B[38;5;0m"
    var abecedari = arrayOf(" Q ", " W ", " E ", " R ", " T ", " Y ", " U ", " I ", " O ", " P ", " A ", " S ", " D ", " F ", " G ", " H ", " J ", " K ", " L ", " Ç ", " Z ", " X ", " C ", " V ", " B ", " N ", " M ")
    var intents = 0
    var encertat = 0
    var trobat = 1
    var intent:String
    var copia:String
    var jugada = Array(6){Array(5){"\u001b[1m\u001b[38;5;0m\u001b[48;2;255;255;255m - "} }

    //Preparar abecedari perquè es pinti bé
    for (l in 0..abecedari.size - 1){
        abecedari[l] = negre.plus(abecedari[l])
    }
    //Imprimir tauler inicial del joc
    println("            WORDLE\n")
    for (i in jugada) {
        print("       ")
        for (j in i) {
            print(j)
        }
        print(reset + "\n")
    }
    print("\n")
    for (i in 0..abecedari.size - 1){
        if (i == 20) print("    ")
        print(abecedari[i])
        if (i == 19 || i == 9 || i == 26) println(reset + " ")
    }
    //Bucle principal del joc que es repeteix per cada paraula llegida
    do {
        println("" + reset)
        intent = readLine().toString().uppercase()
        if (intent.length == 5) {
            // AFEGIR: comprovar que sigui una paraula del diccionari
            /* Intent de comprovar el diccionari
            var trobat = 0
            var len = dict.size - 1
            while (trobat == 0 && i >= 0) {
                if (dict[len] == intent) trobat = 1
                len--
            }
            */
            //if (dict.contains(intent)) {
            if (trobat == 1) {

                if (intent == paraula) {
                    encertat = 1
                }
                //Comprovar i desar com s'han de pintar les lletres
                var j = 0
                copia = paraula
                for (c in intent) {
                    if (c == paraula[j]) {
                        jugada[intents][j] = verd.plus(" ").plus(c).plus(" ")
                        copia = copia.substring(0, j).plus(".").plus(copia.substring(j + 1))
                        //Canviar color de la lletra al teclat
                        for (i in 0..abecedari.size - 1) {
                            if (c == abecedari[i][abecedari[i].length-2]) {
                                abecedari[i] = verd.plus(abecedari[i].substring(abecedari[i].length-3))
                            }
                        }
                    }
                    j++
                }
                j = 0
                for (c in intent) {
                    if (copia.contains(c)) {
                        jugada[intents][j] = groc.plus(" ").plus(c).plus(" ")
                        var k = 0
                        while (copia[k] != c) {
                            k++
                        }
                        copia = copia.substring(0, k).plus(".").plus(copia.substring(k+1))
                        //Canviar color de la lletra al teclat
                        for (i in 0..abecedari.size - 1) {
                            if (c == abecedari[i][abecedari[i].length-2]) {
                                if (abecedari[i].substring(0, abecedari[i].length-3) != verd) abecedari[i] = groc.plus(abecedari[i].substring(abecedari[i].length-3))
                            }
                        }
                    }
                    else if (c != paraula[j]){
                        jugada[intents][j] = gris.plus(" ").plus(c).plus(" ")
                        //Canviar color de la lletra al teclat
                        for (i in 0..abecedari.size - 1) {
                            if (c == abecedari[i][abecedari[i].length-2]) {
                                if (abecedari[i].substring(0, abecedari[i].length-3) != verd && abecedari[i].substring(0, abecedari[i].length-3) != groc) {
                                    abecedari[i] = gris.plus(abecedari[i].substring(abecedari[i].length-3))
                                }
                            }
                        }
                    }
                    j++
                }
                //Imprimir tauler del joc
                for (i in 0..30) println("\n")
                println("            WORDLE\n")
                for (i in jugada) {
                    print("       ")
                    for (j in i) {
                        print(j)
                    }
                    print(reset + "\n")
                }
                print("\n")
                for (i in 0..abecedari.size - 1){
                    if (i == 20) print("    ")
                    print(abecedari[i])
                    if (i == 19 || i == 9 || i == 26) println(reset + " ")
                }
                intents++
            }
            else {
                println(Lvermell + "Paraula incorecte. La paraula he d'estar al diccionari" + reset)
            }
        }
        else {
            println(Lvermell + "Paraula incorrecte. Introdueix una paraula de 5 lletres" + reset)
        }
    } while (intents < 6 && encertat == 0)
    //Imprimir missatges finals del joc
    if (encertat == 1) {
        println("\n" + verd + "         ENHORABONA!!         " + reset)
    }
    else {
        println("\n" + vermell + "            " + paraula + "             " + reset)
    }
}
