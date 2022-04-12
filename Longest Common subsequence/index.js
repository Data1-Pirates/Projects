// Select all the from document using queryselectAll
// var keys = document.querySelectorAll("#calculator span");
// // Define operators
// var operators = ["+", "-", "x", "÷", "^"];
// // Set decimal flag for use later
// var decimalAdded = false;

// loop through all keys
// for (var i = 0; i < keys.length; i++) {
//   //add onclick event to the keys
//   keys[i].onclick = function (e) {
//     // Get the input and button values
//     var input = document.querySelector(".screen");
//     var inputVal = input.innerHTML;
//     var btnVal = this.innerHTML;

//     // If clear key is pressed, erase everything
//     if (btnVal == "C") {
//       input.innerHTML = "";
//       decimalAdded = false;
//     }

//     // If eval key is pressed, calculate and display the result
//     else if (btnVal == "=") {
//       var equation = inputVal; //append equation to variable
//       var lastChar = equation[equation.length - 1]; //target the end of the eval string

//       // Use regex to replace all instances of x, ÷, ^ with *, / and **
//       equation = equation
//         .replace(/x/g, "*")
//         .replace(/÷/g, "/")
//         .replace(/\^/g, "**");

//       //Use regex to remove decimals from the end of an equation
//       if (operators.indexOf(lastChar) > -1 || lastChar == ".")
//         equation = equation.replace(/.$/, "");

//       // use javascript's eval function to get the result

//       if (equation) input.innerHTML = eval(equation);
//       decimalAdded = false;
//     }

//     // Javascript checks

//     // No two operators should be added consecutively.
//     else if (operators.indexOf(btnVal) > -1) {
//       // Get the last character from the equation
//       var lastChar = inputVal[inputVal.length - 1];

//       // Only add operator if input is not empty
//       if (inputVal != "" && operators.indexOf(lastChar) == -1)
//         input.innerHTML += btnVal;
//       // Allow minus operator if the string is empty
//       else if (inputVal == "" && btnVal == "-") input.innerHTML += btnVal;

//       // Replace the last operator (if exists) with the newly pressed operator
//       if (operators.indexOf(lastChar) > -1 && inputVal.length > 1) {
//         input.innerHTML = inputVal.replace(/.$/, btnVal);
//       }

//       decimalAdded = false;
//     }
//     // allow decimal point input
//     else if (btnVal == ".") {
//       if (!decimalAdded) {
//         input.innerHTML += btnVal;
//         decimalAdded = true;
//       }
//     }

//     // if any other key is pressed, just append it after the decimal
//     else {
//       input.innerHTML += btnVal;
//     }

//     // prevent page jumps
//     e.preventDefault();
//   };
// }

//adding keyboard input functionality
document.onkeydown = function (event) {
  var key_press = String.fromCharCode(event.keyCode);
  var key_code = event.keyCode;
  var input = document.querySelector(".screen");
  var inputVal = input.innerHTML;
  var btnVal = this.innerHTML;
  var lastChar = inputVal[inputVal.length - 1];
  var equation = inputVal;
  // Using regex to replace all instances of x, ÷, ^ with *, / and ** respectively.
  equation = equation
    .replace(/x/g, "*")
    .replace(/÷/g, "/")
    .replace(/\^/g, "**");

  // Target each keypress and update the input screen

  if (key_press == 1) {
    input.innerHTML += key_press;
  }
  if (key_press == 2) {
    input.innerHTML += key_press;
  }
  if (key_press == 3 || key_code == 32) {
    input.innerHTML += key_press;
  }
  if (key_press == 4) {
    input.innerHTML += key_press;
  }
  if (key_press == 5) {
    input.innerHTML += key_press;
  }
  if (key_press == 6 && event.shiftKey == false) {
    input.innerHTML += key_press;
  }
  if (key_press == 7) {
    input.innerHTML += key_press;
  }
  if (key_press == 8 && event.shiftKey == false) {
    input.innerHTML += key_press;
  }
  if (key_press == 9) {
    input.innerHTML += key_press;
  }
  if (key_press == 0) {
    input.innerHTML += key_press;
  }

  // Cature operators and prevent from addint two consecutuve operators

  if (
    (inputVal != "" &&
      operators.indexOf(lastChar) == -1 &&
      key_code == 187 &&
      event.shiftKey) ||
    key_code == 107 ||
    (key_code == 61 && event.shiftKey)
  ) {
    document.querySelector(".screen").innerHTML += "+";
  }
  if (
    (inputVal != "" &&
      operators.indexOf(lastChar) == -1 &&
      key_code == 189 &&
      event.shiftKey) ||
    (inputVal != "" && operators.indexOf(lastChar) == -1 && key_code == 107)
  ) {
    document.querySelector(".screen").innerHTML += "-";
  }
  if (
    (inputVal != "" &&
      operators.indexOf(lastChar) == -1 &&
      key_code == 56 &&
      event.shiftKey) ||
    (inputVal != "" && operators.indexOf(lastChar) == -1 && key_code == 106)
  ) {
    document.querySelector(".screen").innerHTML += "x";
  }
  if (
    (inputVal != "" && operators.indexOf(lastChar) == -1 && key_code == 191) ||
    (inputVal != "" && operators.indexOf(lastChar) == -1 && key_code == 111)
  ) {
    document.querySelector(".screen").innerHTML += "÷";
  }
  if (
    inputVal != "" &&
    operators.indexOf(lastChar) == -1 &&
    key_code == 54 &&
    event.shiftKey
  ) {
    document.querySelector(".screen").innerHTML += "^";
  }
  if (key_code == 13 || (key_code == 187 && event.shiftKey == false)) {
    input.innerHTML = eval(equation);
    //reset decimal added flag
    decimalAdded = false;
  }
  if (key_code == 8 || key_code == 46) {
    input.innerHTML = "";
    decimalAdded = false;
  }
};


document.addEventListener('keydown', (event) => {
    var name = event.key;
    var code = event.code;
    if (name === 'Control') {
      // Do nothing.
      return;
    }
    if (event.ctrlKey) {
      alert(`Combination of ctrlKey + ${name} \n Key code Value: ${code}`);
    } else {
      alert(`Key pressed ${name} \n Key code Value: ${code}`);
    }
  }, false);
  // Add event listener on keyup
  document.addEventListener('keyup', (event) => {
    var name = event.key;
    if (name === 'Control') {
      alert('Control key released');
    }
  }, false);







function solve(A, B) {
  let n1 = A.length;
  let n2 = B.length;
  let dp = Array(n1 + 1)
    .fill()
    .map(() => Array(n2 + 1).fill(0));

  for (let i = 0; i <= n1; i++) {
    for (let j = 0; j <= n2; j++) {
      if (i === 0 || j === 0) continue;
      if (A[i - 1] === B[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
      else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  let ans = "";
  let i = n1,
    j = n2;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) i--;
    else if (dp[i][j] == dp[i][j - 1]) j--;
    else if (dp[i][j] == 1 + dp[i - 1][j - 1]) {
      ans = A[i - 1] + ans;
      i--;
      j--;
    }
  }

  console.log(dp[n1][n2]);
  console.log(ans);
}

let A = "ABACABB";
let B = "BABCAB";
solve(A, B);
