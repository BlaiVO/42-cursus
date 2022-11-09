const colors = {
    "verd": 0x3ba83f,
    "groc": 0xd69929,
    "vermell": 0xdd3a3a,
    "negre": 0x000000
};

const paraules = ["PORTA", "COSTA", "BROMA", "ABANS", "COURE", "SORDA", "DIURN", "VIURE", "OSTRA", "MOURE", "LLOSA", "RENTA", "MENTA", "PINTA", "PRUNA", "PROSA", "TOCAT", "SALUT", "MANTA", "FORTA"];
const paraula = paraules[Math.floor(Math.random() * paraules.length)];
const abecedari_raw = [" Q ", " W ", " E ", " R ", " T ", " Y ", " U ", " I ", " O ", " P ", " A ", " S ", " D ", " F ", " G ", " H ", " J ", " K ", " L ", " Ç ", " Z ", " X ", " C ", " V ", " B ", " N ", " M "];
var intents = 0;
var encertat = 0;
var trobat = 1;
var intent;
var copia;

class lletra {
    constructor(lletra, color){
        this.lletra = lletra;
        this.color = color;
    }   
}

let abecedari = []

abecedari_raw.forEach(letter => {
    letter = new lletra(letter, colors["negre"]);
    abecedari.push(letter);
});

abecedari.forEach(l => {
    console.log(l);
    }
);
let test = 'A'
for (let i = 1; i <= 6; i++) {
    for (let j = 1; j <= 5; j++) {
        document.getElementById(`r${i}h${j}`).innerHTML = test;
    }
}