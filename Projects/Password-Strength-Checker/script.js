/**
 * Password Strength Checker Script
 * Author: Elester Charleston
 * Date: 2024-06-09
 */

// Entry point
console.log('Password Strength Checker script loaded.');

// Add your password strength checking logic below
// ============================================
// PASSWORD STRENGTH CHECKER - script.js
// ============================================
// This file handles all the logic for checking
// password strength. Nothing is sent anywhere —
// everything runs right here in the browser.
// ============================================


// --- GRAB ELEMENTS FROM THE HTML ---
// These are the same as pointers/references in C++.
// document.getElementById() finds an element by its id attribute.

const passwordInput = document.getElementById('password-input');
const toggleBtn = document.getElementById('toggle-visibility');
const meterSection = document.getElementById('meter-section');
const meterFill = document.getElementById('meter-fill');
const strengthText = document.getElementById('strength-text');
const crackTime = document.getElementById('crack-time');
const evaluationSection = document.getElementById('evaluation');

// These are the 6 checklist items
const checks = {
    length: document.getElementById('check-length'),
    upper: document.getElementById('check-upper'),
    lower: document.getElementById('check-lower'),
    number: document.getElementById('check-number'),
    special: document.getElementById('check-special'),
    length16: document.getElementById('check-length16')
};


// --- TOGGLE PASSWORD VISIBILITY ---
// When you click the eye icon, swap between type="password" and type="text"
// This is like a boolean toggle — same concept as a flag variable in C++

toggleBtn.addEventListener('click', function () {
    const eyeOpen = document.querySelector('.eye-open');
    const eyeClosed = document.querySelector('.eye-closed');

    if (passwordInput.type === 'password') {
        passwordInput.type = 'text';
        eyeOpen.style.display = 'none';
        eyeClosed.style.display = 'block';
    } else {
        passwordInput.type = 'password';
        eyeOpen.style.display = 'block';
        eyeClosed.style.display = 'none';
    }
});


// --- CHECK PASSWORD ON EVERY KEYSTROKE ---
// 'input' event fires every time the user types or deletes a character.
// This is like a while loop that reacts to user input in real time.

passwordInput.addEventListener('input', function () {
    const password = passwordInput.value;

    // If the input is empty, hide the meter and checklist
    if (password.length === 0) {
        meterSection.classList.remove('visible');
        evaluationSection.classList.remove('visible');
        meterSection.className = 'meter-section';
        meterFill.style.width = '0%';
        strengthText.textContent = 'Enter a password';
        crackTime.textContent = '';
        resetChecks();
        return;  // exit early — same as return in C++
    }

    // Show the meter and checklist
    meterSection.classList.add('visible');
    evaluationSection.classList.add('visible');

    // Run all the checks and count how many pass
    const results = evaluatePassword(password);
    updateChecklist(results);

    // Calculate strength score (0-6)
    const score = Object.values(results).filter(Boolean).length;

    // Update the visual meter and label
    updateMeter(score);
    updateCrackTime(password);
});


// --- EVALUATE PASSWORD ---
// This function checks the password against each evaluation.
// Returns an object (like a struct in C++) with true/false for each.

function evaluatePassword(password) {
    return {
        length: password.length >= 8,
        upper: /[A-Z]/.test(password),       // regex: has uppercase?
        lower: /[a-z]/.test(password),       // regex: has lowercase?
        number: /[0-9]/.test(password),       // regex: has digit?
        special: /[^A-Za-z0-9]/.test(password), // regex: has non-alphanumeric?
    };
}

function updateChecklist(results) {
    for (const key in results) {
        const element = checks[key];
        const icon = element.querySelector('.evaluation-icon');

        if (results[key]) {
            element.classList.add('met');
            icon.textContent = '✓';   // checkmark
        } else {
            element.classList.remove('met');
            icon.textContent = '○';   // empty circle
        }
    }
}


// --- RESET ALL CHECKS ---

function resetChecks() {
    for (const key in checks) {
        checks[key].classList.remove('met');
        checks[key].querySelector('.evaluation-icon').textContent = '○';
    }
}


// --- UPDATE THE STRENGTH METER ---

function updateMeter(score) {
    // Remove old strength classes
    meterSection.className = 'meter-section visible';

    let width, label, strengthClass;

    if (score <= 1) {
        width = '20%';
        label = 'Weak';
        strengthClass = 'strength-weak';
    } else if (score <= 2) {
        width = '40%';
        label = 'Fair';
        strengthClass = 'strength-fair';
    } else if (score <= 3) {
        width = '70%';
        label = 'Strong';
        strengthClass = 'strength-strong';
    } else {
        width = '100%';
        label = 'Very Strong';
        strengthClass = 'strength-very-strong';
    }

    meterFill.style.width = width;
    strengthText.textContent = label;
    meterSection.classList.add(strengthClass);
}


// --- ESTIMATE CRACK TIME ---
function updateCrackTime(password) {
    let poolSize = 0;

    if (/[a-z]/.test(password)) poolSize += 26;
    if (/[A-Z]/.test(password)) poolSize += 26;
    if (/[0-9]/.test(password)) poolSize += 10;
    if (/[^A-Za-z0-9]/.test(password)) poolSize += 32;

    const combinations = Math.pow(poolSize, password.length);

    const guessesPerSecond = 100000000000;
    const seconds = combinations / guessesPerSecond;

    crackTime.textContent = 'Est. crack time: ' + formatTime(seconds);
}


// --- FORMAT TIME INTO READABLE STRING ---

function formatTime(seconds) {
    if (seconds < 1) return 'instant';
    if (seconds < 60) return Math.round(seconds) + ' seconds';
    if (seconds < 3600) return Math.round(seconds / 60) + ' minutes';
    if (seconds < 86400) return Math.round(seconds / 3600) + ' hours';
    if (seconds < 31536000) return Math.round(seconds / 86400) + ' days';
    if (seconds < 31536000 * 1000) return Math.round(seconds / 31536000) + ' years';
    if (seconds < 31536000 * 1000000) return Math.round(seconds / (31536000 * 1000)) + 'k years';
    if (seconds < 31536000 * 1000000000) return Math.round(seconds / (31536000 * 1000000)) + 'M years';
    return 'centuries+';
}