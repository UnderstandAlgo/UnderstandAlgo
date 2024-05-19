



const DSbtn = document.getElementById('DSbtn');
const Abtn = document.getElementById('Abtn');

const menu = document.getElementById('menu');


const DScontent = `
<ul>
    <li><a href="url">Array</a></li>
    <li><a href="url">Stack</a></li>
    <li><a href="url">Tree</a></li>
</ul>
`;

const Acontent = `
<ul>
    <li><a href="url">Searching</a></li>
    <li><a href="url">Sorting</a></li>
</ul>
`;



let showDS = false;
let showA = false;

DSbtn.addEventListener('click', () => {
    showDS = !showDS;
    showA = false; // Ensure only one menu is shown at a time
    updateMenu();
});

Abtn.addEventListener('click', () => {
    showA = !showA;
    showDS = false; // Ensure only one menu is shown at a time
    updateMenu();
});

function updateMenu() {
    if (showDS) {
        menu.innerHTML = DScontent;
    } else if (showA) {
        menu.innerHTML = Acontent;
    } else {
        menu.innerHTML = '';
    }
}

