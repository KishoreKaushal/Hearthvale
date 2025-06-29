
# 🕹️ Game Loop – Notes from Game Programming Patterns

> Source: https://gameprogrammingpatterns.com/game-loop.html

## 🔁 What is a Game Loop?

- A **game loop** runs continuously during gameplay.
- In each iteration, it:
  - Processes user input **without blocking**
  - Updates the game state
  - Renders the game
- It also **tracks the passage of time** to control the speed of gameplay.

## ⏱️ Game Loop vs Traditional UI Event Loops

- In traditional UI systems, the event loop **waits idly** for user input.
- In a game loop, the system **does not block** while waiting.
- The game **keeps animating**, rendering effects, and running logic, regardless of player input.
  - Even if the user is idle, the game remains active—animations play, effects sparkle, monsters attack.

## ⚙️ Responsibilities of the Game Loop

- Ensures the game runs at a **consistent speed**, despite hardware performance differences.
- Keeps the game in sync with **real time**.
- Since the loop is in the **10% of code** where the program spends 90% of its time, it must be **highly efficient and carefully written**.

## 🧠 Pseudocode: Basic Game Loop

```cpp
while (game_is_running) {
  processInput();
  update();
  render();
}
```

This is the foundational form of a game loop—simple, effective, but lacks time management.

## 🕰️ Variable (Fluid) Time Step

### Problem:
- Each update simulates a fixed time slice (e.g. 16 ms).
- But if updating takes longer than 16 ms, the game **lags**.
- The idea: **adjust** the time step based on how long the previous frame took.

### Solution: Variable Time Step

- Calculate how much real time passed since the last update.
- Use that as the time step for the current update.
- This ensures the game **keeps pace with real time** even if the system slows down.

### Pseudocode: Variable Time Step

```cpp
previous = currentTime();
while (game_is_running) {
  current = currentTime();
  elapsed = current - previous;
  previous = current;

  processInput();
  update(elapsed); // use actual time since last frame
  render();
}
```

### Pros:
- Keeps the game running at real-time pace, even on slower machines.

### Cons:
- Physics and animation can become unstable or jittery.
- Larger frame times mean bigger simulation jumps, which can cause inaccuracies.
- Difficult to debug and reproduce states.

## 🪟 Working with the Platform's Event Loop

- Many platforms (Windows, macOS, iOS) **already have an event loop** (for handling UI, OS messages, etc).
- You may need to **integrate your game loop** into the system’s existing event handling:
  - Hook into idle callbacks
  - Use a timer to drive updates
  - Run the game loop on a separate thread (with care)
- Especially important for games inside existing UI frameworks (e.g., Unity plugin, Qt app, or a web game using `requestAnimationFrame`).

### Key Insight:
- Your game doesn't live in isolation. It must **cooperate with the host platform**.

## 🧠 Final Thoughts

- The game loop is **the heartbeat of your game**.
- Getting its structure and timing right is essential for a smooth, playable experience.
- Start simple, and iterate as your game’s needs evolve.

## 🏃‍♂️ Play Catch Up: Fixed Time Step

### Problem with Variable Step:
- Leads to **unstable simulations** (e.g., physics bugs or erratic movement).
- Big time steps = bad simulation results.

### Solution: Fixed Time Step with Accumulator

- Always update the game using **fixed-size time steps** (e.g., 16ms).
- Track how much real time has passed in an **accumulator**.
- Update as many times as needed using that fixed step, until the accumulator is depleted.

### Pseudocode: Fixed Time Step

```cpp
const double MS_PER_UPDATE = 16;
previous = currentTime();
lag = 0.0;

while (game_is_running) {
  current = currentTime();
  elapsed = current - previous;
  previous = current;
  lag += elapsed;

  processInput();
  while (lag >= MS_PER_UPDATE) {
    update(MS_PER_UPDATE);
    lag -= MS_PER_UPDATE;
  }
  render();
}
```

### Advantages:
- Simulation is **stable and predictable**.
- Decouples rendering frequency from update logic.

---

## ⚖️ Stuck in the Middle: Interpolation

- With fixed time steps, rendering may fall between two update states.
- Without fixing this, animation can look **choppy** or **laggy**.

### Solution: Interpolate Between States

- During rendering, calculate how far we are **between updates**.
- Use that fraction (`lag / MS_PER_UPDATE`) to **interpolate** between the last and current states for smooth visuals.

### Pseudocode: Interpolation

```cpp
alpha = lag / MS_PER_UPDATE;
render(interpolate(previousState, currentState, alpha));
```

### Result:
- Keeps update simulation deterministic and simple.
- Achieves **smooth rendering** even with fixed-step updates.
