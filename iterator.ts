// definition
function creeIteratorItervalle(debut = 0,fin = Infinity,pas = 1){
    let prochainIndex = debut;
    let nbIterations = 0

    const rangeIterator = {
        next: function () {
            let resultat;
            if (prochainIndex < fin){
                resultat = { value: prochainIndex, done: false };
                prochainIndex += pas;
                nbIterations++;
                return resultat
            }
            return { value: nbIterations,done: true}
        },

    };
    return rangeIterator;
}

// usage

let it = creeIteratorItervalle(1,10,2);

let resultat = it.next();

while (!resultat.done){
    console.log(resultat.value);
    resultat = it.next();
}





