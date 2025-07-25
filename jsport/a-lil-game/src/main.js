import { Application, Assets, Sprite } from "pixi.js";
import { Text, TextStyle } from "pixi.js";
import * as PIXI from 'pixi.js';


const audio = new Audio("/assets/bgm.wav");

const Tstyle = new TextStyle({
  fontFamily: "Arial",
  fontSize: 36,
  fill: "white", // color of the text
  stroke: "#000000",
  strokeThickness: 4,
  dropShadow: true,
  dropShadowColor: "#000000",
  dropShadowDistance: 2,
});

let currentapp = "Menu";
let app;
let points = 0;
function isColliding(spriteA, spriteB) {
  const boundsA = spriteA.getBounds();
  const boundsB = spriteB.getBounds();

  return boundsA.x < boundsB.x + boundsB.width &&
         boundsA.x + boundsA.width > boundsB.x &&
         boundsA.y < boundsB.y + boundsB.height &&
         boundsA.y + boundsA.height > boundsB.y;
}

async function loadMainScreen() {
  const PlayerText = await Assets.load("/assets/player.png");
  const EnemyText = await Assets.load("/assets/enemy.png");

  const Player = new Sprite(PlayerText);
  Player.anchor.set(0.5);
  Player.position.set(app.screen.width / 2, app.screen.height / 2);
  app.stage.addChild(Player);

  // Array to hold all enemies
  const enemies = [];
  
  // Function to spawn enemy at random location
  function spawnEnemy() {
    const enemy = new Sprite(EnemyText);
    enemy.anchor.set(0.5);
    enemy.position.set(
      Math.random() * app.screen.width,
      Math.random() * app.screen.height
    );
    app.stage.addChild(enemy);
    enemies.push(enemy);
    points += 10;
  }
  
  // Spawn the initial enemy
  spawnEnemy();
  
  // Spawn a new enemy every 15 seconds (15000 ms)
  const spawnInterval = setInterval(() => {
    if (currentapp !== "Main") {
      clearInterval(spawnInterval);
      return;
    }
    spawnEnemy();
  }, 15000);

  document.addEventListener("keydown", function(event) {
    if (currentapp !== "Main") return; // ignore keys if not in game
    if (event.key.toLowerCase() === "w") Player.position.y -= 100;
    if (event.key.toLowerCase() === "a") Player.position.x -= 100;
    if (event.key.toLowerCase() === "s") Player.position.y += 100;
    if (event.key.toLowerCase() === "d") Player.position.x += 100;
  });

  app.ticker.add(() => {
    if (currentapp !== "Main") return;
    
    const message = new Text("PTS: " + points , Tstyle);
    message.x = app.screen.width - 100;
    message.y = app.screen.height - 100;
    message.anchor.set(0.5); // center the text

    // Add it to the stage so it shows up
    app.stage.addChild(message);

    const speed = 2;
    for (const enemy of enemies) {
      const dx = Player.position.x - enemy.position.x;
      const dy = Player.position.y - enemy.position.y;
      const distance = Math.sqrt(dx * dx + dy * dy);
  
      if (distance > 1) {
        enemy.position.x += (dx / distance) * speed;
        enemy.position.y += (dy / distance) * speed;
      }
  
      if (isColliding(Player, enemy)) {
        console.log("Collision");
        currentapp = "Dead";
        points = 0;
        app.stage.removeChildren();  // Clear the stage
        clearInterval(spawnInterval); // Stop spawning
        loadDeadScreen();             // Show dead screen
      }
      if (points >= 100){
        console.log("Win");
        currentapp = "Win";
        points = 0;
        app.stage.removeChildren();  // Clear the stage
        clearInterval(spawnInterval); // Stop spawning
        loadWinScreen();             // Show dead screen
      }
    }
  });
}

async function loadDeadScreen() {
  const DeadText = await Assets.load("/assets/dead.png");
  const DeadSprite = new Sprite(DeadText);
  DeadSprite.anchor.set(0.5);
  DeadSprite.position.set(app.screen.width / 2, app.screen.height / 2);
  app.stage.addChild(DeadSprite);

  const ResButton = await Assets.load("/assets/restart-button.png");
  const ResSprite = new Sprite(ResButton);
  ResSprite.anchor.set(0.5);
  ResSprite.position.set(DeadSprite.position.x, DeadSprite.position.y + 200);
  app.stage.addChild(ResSprite);
  ResSprite.eventMode = "static";
  ResSprite.cursor = "pointer";
  ResSprite.on("pointerdown", async () => {
    console.log("Restarting...");
    currentapp = "Menu";                // <- Reset state
    app.stage.removeChildren();         // <- Clear old screen
    app.ticker.stop();                  // <- Stop old ticker
    app.ticker = new PIXI.Ticker();     // <- Replace ticker with fresh one
    app.ticker.start();                 // <- Start new ticker
    await loadMenu();             // <- Restart game
  });
}

async function loadWinScreen(){
  const DeadText = await Assets.load("/assets/Win.png");
  const DeadSprite = new Sprite(DeadText);
  DeadSprite.anchor.set(0.5);
  DeadSprite.position.set(app.screen.width / 2, app.screen.height / 2);
  app.stage.addChild(DeadSprite);

  const ResButton = await Assets.load("/assets/restart-button.png");
  const ResSprite = new Sprite(ResButton);
  ResSprite.anchor.set(0.5);
  ResSprite.position.set(DeadSprite.position.x, DeadSprite.position.y + 200);
  app.stage.addChild(ResSprite);
  ResSprite.eventMode = "static";
  ResSprite.cursor = "pointer";
  ResSprite.on("pointerdown", async () => {
    console.log("Restarting...");
    currentapp = "Menu";                // <- Reset state
    app.stage.removeChildren();         // <- Clear old screen
    app.ticker.stop();                  // <- Stop old ticker
    app.ticker = new PIXI.Ticker();     // <- Replace ticker with fresh one
    app.ticker.start();                 // <- Start new ticker
    await loadMenu();             // <- Restart game
  });
};

async function loadCreds(){
  const CredTex = await Assets.load("/assets/credits.png");
  const CredSprite = new Sprite(CredTex);
  CredSprite.anchor.set(0.5);
  CredSprite.position.set(app.screen.width / 2, app.screen.height / 2);
  app.stage.addChild(CredSprite);
  document.addEventListener("keydown", async function(event){
      if (currentapp !== "Creds") return;
      if (event.key.toLowerCase() === "x"){
            console.log("Restarting...");
            currentapp = "Menu";                // <- Reset state
            app.stage.removeChildren();         // <- Clear old screen
            app.ticker.stop();                  // <- Stop old ticker
            app.ticker = new PIXI.Ticker();     // <- Replace ticker with fresh one
            app.ticker.start();                 // <- Start new ticker
            await loadMenu();             // <- Restart game
      };
  })

}

async function startMusic(){
  audio.loop = true;
  await audio.play();
};

async function loadMenu(){
  const MenuTex = await Assets.load("/assets/menutxt.png");
  const MenuSprite = new Sprite(MenuTex);
  MenuSprite.anchor.set(0.5);
  MenuSprite.position.set(app.screen.width / 2, app.screen.height / 2);
  app.stage.addChild(MenuSprite);
  document.addEventListener("keydown", async function(event){
      if (currentapp !== "Menu") return;
      if (event.key === " "){
            console.log("Restarting...");
            currentapp = "Main";                // <- Reset state
            app.stage.removeChildren();         // <- Clear old screen
            app.ticker.stop();                  // <- Stop old ticker
            app.ticker = new PIXI.Ticker();     // <- Replace ticker with fresh one
            app.ticker.start();                 // <- Start new ticker
            await loadMainScreen();             // <- Restart game
      };
      if (event.key.toLowerCase() === "c") {
            console.log("Restarting...");
            currentapp = "Creds";                // <- Reset state
            app.stage.removeChildren();         // <- Clear old screen
            app.ticker.stop();                  // <- Stop old ticker
            app.ticker = new PIXI.Ticker();     // <- Replace ticker with fresh one
            app.ticker.start();                 // <- Start new ticker
            await loadCreds();             // <- Restart game     
      };
      if (event.key.toLowerCase() === "p"){
        startMusic();
      }
  })
};

(async () => {
  app = new Application();
  await app.init({ background: "#000000", resizeTo: window });
  document.getElementById("pixi-container").appendChild(app.canvas);

  await loadMenu(); // No need to check `currentapp` here
})();