// Omar Mohammad
// last Edited 9/3

let myELement = document.querySelectorAll(".button");
let screen = document.getElementById("dis")
let operation = document.querySelectorAll(".operation");
let arr = ['÷', '×', '+', '−', '%'];

// iterate over each button to do an event when button is hit
myELement.forEach(function(button) {
    button.addEventListener('click', function() {
        if (screen.value === '0'){
            screen.value = button.innerHTML;
        }
        else {
            screen.value += button.innerHTML;
        }
    });

})


// function to do the operations
operation.forEach(function(operation){
    operation.addEventListener("click", function(){
        if (!arr.includes(screen.value[screen.value.length - 1])){
            screen.value += operation.innerHTML;
        }
        else {
            console.log(screen.value)
        }
    })
})

// delete the equation
let deleteOperation = document.querySelector(".buttonClear");
deleteOperation.onclick = function(){
    screen.value = "";
}

// clear Entry
let buttonClear = document.querySelector(".buttonDel");
buttonClear.onclick = function(){
    if (screen.value > 0)
    console.log(screen.value)
while(!arr.includes(screen.value[screen.value.length - 1]) && screen.value.length){
    screen.value = screen.value.slice(0, -1);
}
}

// add decimal point with some constraints
let decimal = document.getElementById("decimalPoint");

decimal.addEventListener('click', function() {
    if (screen.value.slice(-2) === "0." || screen.value[screen.value.length - 1] === '.') {
        
    } 
    else if (isNaN(parseInt(screen.value[screen.value.length - 1]))) {
        
        screen.value += '0.';
    } 
    else if (!isNaN(parseInt(screen.value[screen.value.length - 1]))) {
        let temp = screen.value.length, temp2 = "";
        while(!arr.includes(screen.value[temp - 1])){
            temp--;
            temp2 += screen.value[temp - 1];
            if (temp == 0){
                break;
            }
        }
        if (temp2.indexOf('.') !== -1){
            console.log("hey")
        }
        else screen.value += '.';
    }
});

// an event listener to do something when equal button is hit
let equalButton = document.getElementById("equals");
equalButton.addEventListener("click", function() {
    let temp = screen.value;
    temp = temp.replace(/×/g, '*');
    temp = temp.replace(/÷/g, '/');
    temp = temp.replace(/−/g, '-');
    console.log(temp);
    screen.value = eval(temp);
});


