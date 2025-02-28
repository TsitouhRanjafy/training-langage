// definition
function creeIteratorItervalle(debut, fin, pas) {
    if (debut === void 0) { debut = 0; }
    if (fin === void 0) { fin = Infinity; }
    if (pas === void 0) { pas = 1; }
    var prochainIndex = debut;
    var nbIterations = 0;
    var rangeIterator = {
        next: function () {
            var resultat;
            if (prochainIndex < fin) {
                resultat = { value: prochainIndex, done: false };
                prochainIndex += pas;
                nbIterations++;
                return resultat;
            }
            return { value: nbIterations, done: true };
        },
    };
    return rangeIterator;
}
// usage
var it = creeIteratorItervalle(1, 10, 2);
var resultat = it.next();
while (!resultat.done) {
    console.log(resultat.value);
    resultat = it.next();
}
