const navLinks = document.querySelectorAll('nav a');
var loginBtn = document.getElementById('login-nav');
var closeEl = document.getElementById('close');
var getModal = document.getElementsByClassName('container-modal');
console.log(getModal[0]);
navLinks.forEach((link) => {
    console.log(link);

    link.addEventListener('click',(e) => {
        e.preventDefault();
        const href = link.getAttribute('href');
        window.location.href = href;
    });
});

loginBtn.addEventListener('click',(e) => {
    e.preventDefault(e);
    getModal[0].classList.add('open');
});

closeEl.addEventListener('click',(e) => {
    e.preventDefault(e);
    getModal[0].classList.remove('open');
});
function myFunction() {
    var x = document.getElementById("myTopnav");
    if (x.className === "topnav") {
        x.className += " responsive";
    } else {
        x.className = "topnav";
    }
}