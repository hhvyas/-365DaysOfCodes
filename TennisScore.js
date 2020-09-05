var Fscore = document.querySelector("#p1");
var Sscore = document.querySelector("#p2");
var reset = document.querySelector("#reset");
var seef = document.querySelector("#sfp");
var sees = document.querySelector("#sps");
var ts = document.querySelector("#ts");
var seto = document.querySelector("#stf");
var sett = document.querySelector("#sts");
var newg = document.querySelector("#new");
var aski = document.querySelector("#aski");
var ask = true;
var rem = 0;
if (ask==true){
	var score = Number(prompt("Number of Set in Match?"));
	rem = score;
	ask=false;
}
ts.textContent = rem;
var fs = 0;
var sc = 0;
var setf = 0;
var sets = 0;
seto.textContent = setf;
sett.textContent = sets;
newg.addEventListener("click",newGame);
Fscore.addEventListener("click",firstx);
Sscore.addEventListener("click",secondx);
function newGame(){
	fs = 0;
	sc = 0;
	seef.textContent = fs;
	sees.textContent = sc;
	seto.textContent = setf;
	sett.textContent = sets;
	document.querySelector("#p1").disabled = false;
	document.querySelector("#p2").disabled = false;
	Sscore.style.color = "black";
	Fscore.style.color = "black";
}
function firstx(){
	fs++;
	seef.textContent = fs;
	if (fs == 4){
		setf++;
		Sscore.style.color = "red";
		Fscore.style.color = "green";
		disableButton();
		updateScore();
		updateScoreBoard();
	}
}
function secondx(){
	sc++;
	sees.textContent = sc;
	if (sc == 4){
		sets++;
		Sscore.style.color = "green";
		Fscore.style.color = "red";
		disableButton();
		updateScore();
		updateScoreBoard();
	}
}
function disableButton(){
	document.querySelector("#p1").disabled = true;
	document.querySelector("#p2").disabled = true;
}
function updateScore(){
	rem--;
	updateScoreBoard();
	var FinalScore;
	if (score%2==0){
		FinalScore = 1+score/2;
	}else{
		FinalScore = (score+1)/2;
	}
	if (setf == FinalScore){
		alert("Player 1 Won The Match!");
		location.reload();
	}
	if (sets == FinalScore){
		alert("Player 2 Won The Match!");
		location.reload();
	}
}
function updateScoreBoard(){
	seto.textContent = setf;
	sett.textContent = sets;
	ts.textContent = rem;
}
