const DSbtn = document.getElementById('DSbtn');
const Abtn = document.getElementById('Abtn');
const menu = document.getElementById('menu');
const codeBox = document.getElementById('code-box');

const DScontent = `
<ul>
    <li>
        <button onclick="toggleSubmenu('arraySubmenu')">Array</button>
        <ul id="arraySubmenu" class="submenu">
            <li><button onclick="loadCode('codes/array_cpp.txt')">C++</button></li>
            <li><button onclick="loadCode('codes/array_c.txt')">C</button></li>
        </ul>
    </li>
    <li>
        <button onclick="toggleSubmenu('stackSubmenu')">Stack</button>
        <ul id="stackSubmenu" class="submenu">
            <li><button onclick="loadCode('codes/stack_cpp.txt')">C++</button></li>
            <li><button onclick="loadCode('codes/stack_c.txt')">C</button></li>
        </ul>
    </li>
    <li>
        <button onclick="toggleSubmenu('treeSubmenu')">Tree</button>
        <ul id="treeSubmenu" class="submenu">
            <li><button onclick="loadCode('codes/tree_cpp.txt')">C++</button></li>
            <li><button onclick="loadCode('codes/tree_c.txt')">C</button></li>
        </ul>
    </li>
</ul>
`;

const Acontent = `
<ul>
    <li>
        <button onclick="toggleSubmenu('searchingSubmenu')">Searching</button>
        <ul id="searchingSubmenu" class="submenu">
            <li><button onclick="loadCode('codes/bfs_cpp.txt')">BFS - C++</button></li>
            <li><button onclick="loadCode('codes/bfs_c.txt')">BFS - C</button></li>
        </ul>
    </li>
    <li>
        <button onclick="toggleSubmenu('sortingSubmenu')">Sorting</button>
        <ul id="sortingSubmenu" class="submenu">
            <li><button onclick="loadCode('codes/sorting_cpp.txt')">C++</button></li>
            <li><button onclick="loadCode('codes/sorting_c.txt')">C</button></li>
        </ul>
    </li>
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

function toggleSubmenu(id) {
    const submenu = document.getElementById(id);
    submenu.style.display = submenu.style.display === 'none' ? 'block' : 'none';
}

function loadCode(filePath) {
    fetch(filePath)
        .then(response => response.text())
        .then(data => {
            codeBox.value = data;
        })
        .catch(error => {
            codeBox.value = 'Error loading code.';
            console.error('Error:', error);
        });
}
