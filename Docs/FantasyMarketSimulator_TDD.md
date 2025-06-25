# 🛠️ Fantasy Market Simulator – Technical Design Document

## 📌 Overview
A semi-realistic, first-person medieval market simulator built in Unreal Engine 5.5 using C++ and Blueprints.  
This TDD outlines the core architecture, major systems, and class responsibilities.

---

## 📁 Project Structure

### Unreal Content Folder (`/Content/`)
```
/Blueprints/
    /UI/
    /Crafting/
    /Systems/
    ...
/UI/
/DataTables/
/Meshes/
/Materials/
/Audio/
```

### C++ Source Folder (`/Source/FantasyMarketSimulator/`)
```
/Public/
/Private/
    /Characters/
    /Managers/
    /Systems/
    /UI/
    /Input/
    /Interfaces/
```

---

## 🎮 Gameplay Loop (High-Level)
1. Open shop  
2. Serve customers or fulfill tasks  
3. Earn gold and spend on upgrades/crafting  
4. Close shop and review summary  
5. Repeat with progression

---

## 🧱 Core Systems

### 1. Player & Controls
| Component            | Type            | Notes |
|----------------------|------------------|-------|
| `AFMPlayerCharacter` | C++             | Handles movement, camera, and interaction logic |
| Input System         | Enhanced Input  | `IA_Move`, `IA_Look`, `IA_Interact` |

### 2. Shop Management
| Component        | Type | Description |
|------------------|------|-------------|
| `ShopManager`    | C++  | Manages shop state, gold, open/closed status |
| `WBP_HUD`        | BP   | UI overlay for gold, time, shop state |
| `OpenSignActor`  | BP   | Interactive object toggling shop state |

### 3. Time System
| Component        | Type | Description |
|------------------|------|-------------|
| `TimeManager`    | C++  | Tick-based clock system, feeds UI |
| `Clock UI`       | BP   | Binds to TimeManager for display |

### 4. Inventory System
| Component              | Type     | Description |
|------------------------|----------|-------------|
| `InventoryManager`     | C++      | Central system tracking player/store inventory |
| `InventorySlotWidget`  | BP       | Drag/drop slot UI |
| `Item DataTable`       | CSV/UE   | Defines item types, stats, and names |

### 5. Crafting System
| Component          | Type | Description |
|--------------------|------|-------------|
| `CraftingManager`  | C++  | Combines inputs into crafted products |
| Recipes            | DT   | Data-driven recipes used by manager |

### 6. AI & Workers *(Planned in Phase 4)*
| Component      | Type    | Description |
|----------------|---------|-------------|
| `WorkerPawn`   | BP      | AI-controlled actor that handles shop tasks |
| `TaskQueue`    | BP+C++  | Queue system for work assignments |

---

## 🧪 Testing & Debugging (Planned)
- Blueprint-based debug toggles  
- Optional: Unit test automation post-core

---

## 🛠 Asset Pipeline (Phase 5)
| Step              | Tool     | Notes |
|-------------------|----------|-------|
| Model creation    | Blender  | Modeled and UV’d tools/potions/barrels |
| Import to UE      | UE5      | Use LODs, collisions, scale conventions |
| Placeholder swap  | UE5      | Replace with custom meshes once validated |

---

## 🚀 Build & Deployment
| Task                   | Notes |
|------------------------|-------|
| CI Pipeline (planned)  | Build on Git push |
| Demo Packaging         | Create shareable Windows standalone |

---

## 📌 Development Notes
- Performance-critical systems prioritized for C++  
- UI and interaction prototyped in Blueprint  
- Uses GitHub Projects + Issues for tracking  
- Supports modular, testable architecture
