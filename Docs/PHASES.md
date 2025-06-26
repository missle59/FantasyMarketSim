# 📅 Project Phases – Fantasy Market Simulator

This document provides a breakdown of the project development phases, tasks, and completion status for Fantasy Market Simulator.

---

## ✅ Phase 0: Setup & Baseline – *Complete*

- [x] Install development tools: Unreal Engine 5.5, Rider IDE, Git LFS, Blender
- [x] Initialize Git repository with branching strategy and .gitignore (UE + Rider)
- [x] Create and structure `/Content/` folders (Blueprints, UI, Crafting, etc.)
- [x] Create and structure Rider C++ folders (Public/Private for Managers, UI, Systems, Input, etc.)
- [x] Create and configure core classes:
  - [x] `AFMPlayerCharacter` (C++) — 'FM' prefix stands for Fantasy Market
  - [x] `AFMGameMode` (C++) — Fantasy Market Game Mode
- [x] Implement `TimeManager` and `ShopManager` systems (tick-based updates)
- [x] Create CSV task list and import into GitHub Project board
- [x] Verify project compiles with no errors in Rider

---

## ⏳ Phase 1: Engine Foundations – *In Progress*

- [x] Create custom `FMGameMode` and assign to project
- [x] Create first-person character (`AFMPlayerCharacter`) with camera and capsule
- [x] Set up Enhanced Input system:
  - [x] Move
  - [x] Look
  - [ ] Interact (E)
- [ ] Implement `SetupPlayerInputComponent` and line trace interaction logic
- [ ] Create Open/Closed sign as interactive in-world actor
- [ ] Build `WBP_HUD` Blueprint widget for in-game UI
- [ ] Add HUD to viewport from PlayerController or Pawn
- [ ] Display current shop status, clock (time of day), and gold in HUD
- [ ] Add toggleable UI key (e.g., Tab) to open extended shop interfaces
- [ ] Bind values in HUD using data from `TimeManager` and `ShopManager`

---

## 🔜 Phase 2: Blueprint Prototyping – *Planned*

- [ ] Design drag/drop inventory UI
- [ ] Create `InventorySlot` widgets
- [ ] Implement basic item pickup and drag logic
- [ ] Add test items to world for pickup

---

## 🔜 Phase 3: Core Logic in C++ – *Planned*

- [ ] Create `InventoryManager` class
- [ ] Implement item definitions via DataTables
- [ ] Implement `CraftingManager` for ingredients ➔ product
- [ ] Add `PricingAlgorithm` for supply/demand-based margins

---

## 🔜 Phase 4: Worker AI & Task Queues – *Planned*

- [ ] Create AI-controlled `WorkerPawn`
- [ ] Add basic patrol, gather, deliver tasks
- [ ] Implement `TaskQueue` system (Blueprint + C++)

---

## 🔜 Phase 5: Asset Pipeline – *Planned*

- [ ] Model 2–3 items in Blender (tools, potions, barrels)
- [ ] Import to UE5 with proper collisions, LODs
- [ ] Replace placeholder meshes

---

## 🔜 Phase 6: Polish & Build – *Planned*

- [ ] Implement SaveGame logic
- [ ] Optimize world (instancing, LODs)
- [ ] Setup CI to build project on push
- [ ] Package standalone demo build
