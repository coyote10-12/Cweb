const PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

const outputEl = document.getElementById("output");
const v1Panel = document.getElementById("v1-panel");
const modeToggle = document.getElementById("modeToggle");

function out(msg) {
    outputEl.textContent = msg;
}

// Dark/light mode
modeToggle.addEventListener("change", () => {
    document.body.classList.toggle("light");
});

// Menu buttons
document.querySelectorAll(".btn[data-action]").forEach(btn => {
    btn.addEventListener("click", () => {
        const action = btn.getAttribute("data-action");
        v1Panel.classList.add("hidden");

        if (action === "basic") basicCalc();
        else if (action === "areaCircle") areaCircle();
        else if (action === "heightObject") heightObject();
        else if (action === "circumference") circumference();
        else if (action === "v1") {
            v1Panel.classList.remove("hidden");
            out("V1 cockpit ready. Enter parameters and press Compute.");
        }
        else if (action === "cylinder") cylinderVolume();
        else if (action === "sphereArea") sphereArea();
        else if (action === "sphereVolume") sphereVolume();
        else if (action === "quiz") quiz();
    });
});

/* BASIC CALCULATOR */
function basicCalc() {
    let num1 = parseFloat(prompt("Enter 1st number"));
    let op = prompt("Enter operator (+, -, *, /)");
    let num2 = parseFloat(prompt("Enter 2nd number"));

    let result;
    if (op === "+") result = num1 + num2;
    else if (op === "-") result = num1 - num2;
    else if (op === "*") result = num1 * num2;
    else if (op === "/") result = num1 / num2;
    else return out("Invalid operator.");

    out("Result: " + result);
}

/* AREA OF CIRCLE */
function areaCircle() {
    let r = parseFloat(prompt("Radius?"));
    out("Area = " + (r * r * PI));
}

/* HEIGHT OF OBJECT */
function heightObject() {
    let d = parseFloat(prompt("Distance?"));
    let deg = parseFloat(prompt("Angle?"));

    if (deg === 45) out("Height = " + d);
    else {
        let one = d * Math.tan(deg);
        let two = one - one - one - one;
        out("Height = " + (one + two));
    }
}

/* CIRCUMFERENCE */
function circumference() {
    let r = parseFloat(prompt("Radius?"));
    out("Circumference = " + (2 * PI * r));
}

/* SECRET QUIZ */
function quiz() {
    let diff = prompt("Difficulty: e, m, h, x");

    function ask(q, correct) {
        let n = parseFloat(prompt(q));
        return n === correct;
    }

    if (diff === "e") {
        if (!ask("6 + 8?", 14)) return out("Incorrect");
        if (!ask("3 + 12?", 15)) return out("Incorrect");
        if (!ask("32 + 18?", 50)) return out("Incorrect");
        if (!ask("40 - 10?", 30)) return out("Incorrect");
        return out("Correct!");
    }

    if (diff === "m") {
        if (!ask("34 + 86?", 120)) return out("Incorrect");
        if (!ask("3236 - 1209?", 2027)) return out("Incorrect");
        if (!ask("32 * 18?", 576)) return out("Incorrect");
        if (!ask("40 / 10?", 4)) return out("Incorrect");
        return out("Correct!");
    }

    if (diff === "h") {
        if (!ask("68 * 88?", 5984)) return out("Incorrect");
        if (!ask("5556.5 / 883.45 (nearest tenth)?", 6.2)) return out("Incorrect");
        if (!ask("32.18 / 18.32 (nearest hundredth)?", 1.75)) return out("Incorrect");
        return out("Correct!");
    }

    if (diff === "x") {
        if (!ask("634 / 2836 (nearest thousandth)?", 0.223)) return out("Incorrect");
        return out("Correct!");
    }

    out("Invalid difficulty.");
}

/* V1 COCKPIT */
const rlInput = document.getElementById("rl");
const accelInput = document.getElementById("accel");
const vrInput = document.getElementById("vr");
const vrUnitSelect = document.getElementById("vrUnit");
const v1Display = document.getElementById("v1Display");
const v1DistDisplay = document.getElementById("v1DistDisplay");
const vrStatus = document.getElementById("vrStatus");
const v1Graph = document.getElementById("v1Graph");
const ctx = v1Graph.getContext("2d");

document.getElementById("computeV1").addEventListener("click", () => {

    // Throttle animation
    const lever = document.getElementById("lever");
    if (lever) {
        lever.classList.add("lever-forward");
        setTimeout(() => lever.classList.remove("lever-forward"), 2000);
    }

    const rl = parseFloat(rlInput.value);
    const a = parseFloat(accelInput.value);
    const vrVal = parseFloat(vrInput.value);
    const unit = vrUnitSelect.value;

    if (isNaN(rl) || isNaN(a) || isNaN(vrVal) || rl <= 0 || a <= 0) {
        out("Enter valid positive numbers for runway and acceleration.");
        return;
    }

    // Convert Vr to ft/s
    let vr_fts;
    if (unit === "kts") vr_fts = vrVal * 1.68781;
    else if (unit === "mph") vr_fts = vrVal * 1.46667;
    else vr_fts = vrVal * 0.911344;

    // Distance needed to reach Vr
    const s_total = (vr_fts * vr_fts) / (2 * a);

    if (s_total > rl) {
        vrStatus.textContent = "NO";
        v1Display.textContent = "--";
        v1DistDisplay.textContent = "--";
        document.getElementById("runwayProgress").style.width = "0%";

        out(
            "You cannot reach Vr on this runway.\n" +
            "Needed: " + s_total.toFixed(0) + " ft\n" +
            "Runway: " + rl.toFixed(0) + " ft"
        );
        return;
    }

    // Vr reachable
    vrStatus.textContent = "YES";

    // V1 = halfway down runway (toy model)
    const s_v1 = rl / 2;
    const v1_fts = Math.sqrt(2 * a * s_v1);

    // Convert V1 back to user units
    let v1_out;
    if (unit === "kts") v1_out = v1_fts / 1.68781;
    else if (unit === "mph") v1_out = v1_fts / 1.46667;
    else v1_out = v1_fts / 0.911344;

    v1Display.textContent = v1_out.toFixed(1) + " " + unit;
    v1DistDisplay.textContent = s_v1.toFixed(0) + " ft";

    // Runway progress bar
    const progressPercent = (s_v1 / rl) * 100;
    document.getElementById("runwayProgress").style.width = progressPercent + "%";

    out(
        "Approx V1 = " + v1_out.toFixed(1) + " " + unit +
        "\nDistance to V1 ≈ " + s_v1.toFixed(0) + " ft"
    );

    drawV1Graph(rl, a, vr_fts, s_v1, v1_fts);
});

/* GRAPH: speed vs distance */
function drawV1Graph(rl, a, vr_fts, s_v1, v1_fts) {
    ctx.clearRect(0, 0, v1Graph.width, v1Graph.height);

    const w = v1Graph.width;
    const h = v1Graph.height;

    // Axes
    ctx.strokeStyle = "#4af";
    ctx.lineWidth = 1.5;
    ctx.beginPath();
    ctx.moveTo(40, h - 30);
    ctx.lineTo(w - 10, h - 30);
    ctx.moveTo(40, h - 30);
    ctx.lineTo(40, 10);
    ctx.stroke();

    // Labels
    ctx.fillStyle = "#4af";
    ctx.font = "12px Arial";
    ctx.fillText("Distance (ft)", w / 2 - 30, h - 10);

    ctx.save();
    ctx.translate(15, h / 2 + 20);
    ctx.rotate(-Math.PI / 2);
    ctx.fillText("Speed (ft/s)", 0, 0);
    ctx.restore();

    const maxDist = rl;
    const maxSpeed = Math.max(vr_fts, v1_fts) * 1.2;

    function xFromDist(s) {
        return 40 + (s / maxDist) * (w - 60);
    }
    function yFromSpeed(v) {
        return (h - 30) - (v / maxSpeed) * (h - 50);
    }

    // Speed curve
    ctx.strokeStyle = "#0f0";
    ctx.lineWidth = 2;
    ctx.beginPath();
    for (let s = 0; s <= maxDist; s += maxDist / 100) {
        const v = Math.sqrt(2 * a * s);
        const x = xFromDist(s);
        const y = yFromSpeed(v);
        if (s === 0) ctx.moveTo(x, y);
        else ctx.lineTo(x, y);
    }
    ctx.stroke();

    // Vr marker
    ctx.fillStyle = "#f00";
    const s_vr = (vr_fts * vr_fts) / (2 * a);
    const xVr = xFromDist(Math.min(s_vr, maxDist));
    const yVr = yFromSpeed(vr_fts);
    ctx.beginPath();
    ctx.arc(xVr, yVr, 4, 0, Math.PI * 2);
    ctx.fill();
    ctx.fillText("Vr", xVr + 5, yVr - 5);

    // V2 marker
    const v2_fts = vr_fts * 1.2;
    const s_v2 = (v2_fts * v2_fts) / (2 * a);
    ctx.fillStyle = "#00f";
    const xV2 = xFromDist(Math.min(s_v2, maxDist));
    const yV2 = yFromSpeed(v2_fts);
    ctx.beginPath();
    ctx.arc(xV2, yV2, 4, 0, Math.PI * 2);
    ctx.fill();
    ctx.fillText("V2", xV2 + 5, yV2 - 5);
}
