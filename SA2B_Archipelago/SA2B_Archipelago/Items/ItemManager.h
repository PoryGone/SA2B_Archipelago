#include "../pch.h"
#pragma once

#include <map>
#include <queue>
#include <vector>
#include "ItemData.h"
#include "../ModLoaderCommon/Trampoline.h"

FunctionPointer(double, sa2b_ceil, (double a1), 0x007A7B50);

constexpr unsigned int AP_ITEM_ID_OFFSET = 0xFF0000;
constexpr unsigned int TRAP_DURATION = 600;
constexpr unsigned int TRAP_COOLDOWN = 60;
constexpr unsigned int JUNK_COOLDOWN = 210;

class ItemManager
{
public:
	static ItemManager& getInstance()
	{
		static ItemManager instance;
		return instance;
	}

	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();

	// Item Functions
	void ResetItems();
	void ReceiveItem(int item_id, bool notify);
	bool IsOmotrapActive();
	void HandleJunk(int item_id);

	std::vector<int> GetChaosEmeraldAddresses();

	int _TimeStopTimer;

private:
	void HandleEquipment(int EquipmentItem);
	void HandleTrap(int item_id);
	bool IsActiveTrapValid();
	void ResetTrapData();
	void OnFrameJunkQueue();
	void OnFrameTrapQueue();
	void OnFrameDialogueQueue();

	void AddRandomDialogueToQueue();

	const HelperFunctions* _helperFunctions;

	std::map<int, ItemData> _ItemData;
	int _thisSessionChecksReceived = 0;
	unsigned __int8 _EmblemsReceived = 0;

	std::queue<int> _JunkQueue;
	std::queue<int> _TrapQueue;
	std::queue<DialogueData> _DialogueQueue;

	int _ActiveTrap = 0;
	int _ActiveTrapTimer = 0;
	int _TrapCooldownTimer = TRAP_COOLDOWN;
	int _JunkCooldownTimer = 0;
	int _ActiveDialogueTimer = 0;

	FogData _StoredFogData;

	NJS_VECTOR _TimeStopPos;

	PhysicsData _StoredPhysicsData;

	CharObj2Base* _p2Obj;


	std::array<std::array<DialogueData, 7>, 49> _dialogueOptions = { {
		{ DialogueData(2590, 4), DialogueData(2591, 5), DialogueData(2592, 5), DialogueData(2593, 9), DialogueData(2594, 5), DialogueData(), DialogueData() },               // DC
		{ DialogueData(2595, 4), DialogueData(2596, 7), DialogueData(2597, 8), DialogueData(2598, 8), DialogueData(), DialogueData(), DialogueData() },                      // KingBoomBoo
		{ DialogueData(2599, 3), DialogueData(2600, 5), DialogueData(2601, 5), DialogueData(2602, 4), DialogueData(2603, 4), DialogueData(), DialogueData() },               // EggGolem S
		{ DialogueData(2604, 4), DialogueData(2605, 7), DialogueData(2606, 5), DialogueData(2607, 3), DialogueData(2608, 3), DialogueData(), DialogueData() },               // EE
		{ DialogueData(2609, 4), DialogueData(2610, 8), DialogueData(2611, 4), DialogueData(2612, 3), DialogueData(), DialogueData(), DialogueData() },                      // MH

		{ DialogueData(2613, 4), DialogueData(2614, 6), DialogueData(2615, 7), DialogueData(2616, 3), DialogueData(2617, 7), DialogueData(2618, 5), DialogueData(2619, 5) }, // CC
		{ DialogueData(2620, 5), DialogueData(2621, 5), DialogueData(2622, 5), DialogueData(2623, 6), DialogueData(), DialogueData(), DialogueData() },                      // Biolizard
		{ DialogueData(2624, 3), DialogueData(2625, 6), DialogueData(2626, 6), DialogueData(2628, 5), DialogueData(2629, 6), DialogueData(), DialogueData() },               // Finalhazard

		{ DialogueData(2630, 4), DialogueData(2631, 5), DialogueData(2632, 7), DialogueData(2633, 3), DialogueData(), DialogueData(), DialogueData() },                      // K v R
		{ DialogueData(2634, 3), DialogueData(2635, 4), DialogueData(2636, 5), DialogueData(2637, 4), DialogueData(2638, 3), DialogueData(), DialogueData() },               // CG
		{ DialogueData(2639, 4), DialogueData(2640, 7), DialogueData(2641, 4), DialogueData(2642, 8), DialogueData(), DialogueData(), DialogueData() },                      // T v E 2
		{ DialogueData(2643, 3), DialogueData(2644, 5), DialogueData(2645, 3), DialogueData(2646, 5), DialogueData(), DialogueData(), DialogueData() },                      // FR
		{ DialogueData(2647, 3), DialogueData(2648, 9), DialogueData(2649, 4), DialogueData(), DialogueData(), DialogueData(), DialogueData() },                             // S v Sh 2


		{ DialogueData(2551, 5), DialogueData(2552, 10), DialogueData(2553, 4), DialogueData(), DialogueData(), DialogueData(), DialogueData() },                            // R v K
		{ DialogueData(2554, 5), DialogueData(2555, 5), DialogueData(2556, 6), DialogueData(2557, 3), DialogueData(2558, 5), DialogueData(), DialogueData() },               // CW

		{ DialogueData(2559, 4), DialogueData(2560, 6), DialogueData(2561, 5), DialogueData(2562, 6), DialogueData(2563, 4), DialogueData(), DialogueData() },               // AM

		{ DialogueData(2564, 5), DialogueData(2565, 13), DialogueData(2566, 8), DialogueData(), DialogueData(), DialogueData(), DialogueData() },                            // E v T 2
		{ DialogueData(2567, 5), DialogueData(2568, 9), DialogueData(2569, 7), DialogueData(2570, 7), DialogueData(), DialogueData(), DialogueData() },                      // FC
		{ DialogueData(2571, 5), DialogueData(2572, 5), DialogueData(2573, 5), DialogueData(2574, 4), DialogueData(2575, 8), DialogueData(), DialogueData() },               // Sh v S 2

		{ DialogueData(2576, 5), DialogueData(2577, 5), DialogueData(2578, 3), DialogueData(2579, 5), DialogueData(2580, 5), DialogueData(2581, 2), DialogueData() },        // R101
		{ DialogueData(2582, 4), DialogueData(2583, 6), DialogueData(2584, 4), DialogueData(2585, 5), DialogueData(2586, 4), DialogueData(), DialogueData() },               // HB
		{ DialogueData(2587, 3), DialogueData(2588, 5), DialogueData(2589, 6), DialogueData(), DialogueData(), DialogueData(), DialogueData() },                             // PC


		{ DialogueData(2513, 4), DialogueData(2514, 4), DialogueData(2515, 9), DialogueData(2516, 5), DialogueData(2517, 4), DialogueData(2518, 3), DialogueData() },        // MS

		{ DialogueData(2519, 5), DialogueData(2520, 5), DialogueData(2521, 6), DialogueData(), DialogueData(), DialogueData(), DialogueData() },                             // SH
		{ DialogueData(2522, 5), DialogueData(2523, 4), DialogueData(2524, 6), DialogueData(2525, 5), DialogueData(2526, 10), DialogueData(2527, 3), DialogueData() },       // FlyingDog
		{ DialogueData(2528, 5), DialogueData(2529, 3), DialogueData(2530, 6), DialogueData(2531, 5), DialogueData(), DialogueData(), DialogueData() },                      // WJ
		{ DialogueData(2532, 5), DialogueData(2533, 4), DialogueData(2534, 6), DialogueData(), DialogueData(), DialogueData(), DialogueData() },                             // Sh v S 1
		{ DialogueData(2535, 5), DialogueData(2536, 8), DialogueData(2537, 3), DialogueData(2538, 6), DialogueData(), DialogueData(), DialogueData() },                      // R280
		{ DialogueData(2539, 5), DialogueData(2540, 7), DialogueData(2541, 8), DialogueData(), DialogueData(), DialogueData(), DialogueData() },                             // SR
		{ DialogueData(2542, 5), DialogueData(2543, 9), DialogueData(2544, 9), DialogueData(2545, 4), DialogueData(), DialogueData(), DialogueData() },                      // EggGolem E
		{ DialogueData(2546, 5), DialogueData(2547, 2), DialogueData(2548, 4), DialogueData(2549, 6), DialogueData(2550, 8), DialogueData(), DialogueData() },               // MS


		{ DialogueData(2472, 5), DialogueData(2473, 10), DialogueData(2474, 7), DialogueData(2475, 3), DialogueData(2476, 7), DialogueData(2477, 3), DialogueData() },       // IG
		{ DialogueData(2478, 5), DialogueData(2479, 4), DialogueData(2480, 5), DialogueData(2481, 4), DialogueData(2482, 10), DialogueData(), DialogueData() },	             // HotShot
		{ DialogueData(2483, 5), DialogueData(2484, 6), DialogueData(2485, 5), DialogueData(2486, 7), DialogueData(2487, 2), DialogueData(2488, 3), DialogueData() },        // DL
		{ DialogueData(2489, 5), DialogueData(2490, 5), DialogueData(2491, 5), DialogueData(2492, 5), DialogueData(), DialogueData(), DialogueData() },                      // SO
		{ DialogueData(2493, 4), DialogueData(2494, 4), DialogueData(2495, 10), DialogueData(2496, 5), DialogueData(), DialogueData(), DialogueData() },                     // RH
		{ DialogueData(2497, 5), DialogueData(2498, 5), DialogueData(2499, 3), DialogueData(2500, 5), DialogueData(2501, 5), DialogueData(), DialogueData() },               // EQ
		{ DialogueData(2502, 5), DialogueData(2503, 4), DialogueData(2504, 6), DialogueData(), DialogueData(), DialogueData(), DialogueData() },                             // LC
		{ DialogueData(2505, 5), DialogueData(2506, 4), DialogueData(2507, 7), DialogueData(2508, 6), DialogueData(), DialogueData(), DialogueData() },                      // WB
		{ DialogueData(2509, 5), DialogueData(2510, 6), DialogueData(2511, 4), DialogueData(2512, 4), DialogueData(), DialogueData(), DialogueData() },                      // E v T 1


		{ DialogueData(2411, 3), DialogueData(2412, 7), DialogueData(2413, 8), DialogueData(2414, 4), DialogueData(2415, 3), DialogueData(), DialogueData() },               // CE
		{ DialogueData(2416, 3), DialogueData(2417, 5), DialogueData(2418, 6), DialogueData(2419, 3), DialogueData(2420, 6), DialogueData(), DialogueData() },               // BigFoot
		{ DialogueData(2421, 4), DialogueData(2422, 4), DialogueData(2423, 4), DialogueData(2424, 12), DialogueData(2425, 8), DialogueData(2426, 6), DialogueData() },       // WC
		{ DialogueData(2427, 4), DialogueData(2428, 6), DialogueData(2429, 4), DialogueData(2430, 6), DialogueData(2431, 6), DialogueData(2432, 4), DialogueData(2433, 3) }, // T v E 1
		{ DialogueData(2434, 4), DialogueData(2435, 9), DialogueData(2436, 5), DialogueData(2437, 7), DialogueData(), DialogueData(), DialogueData() },                      // PL
		{ DialogueData(2438, 3), DialogueData(2439, 3), DialogueData(2440, 8), DialogueData(2441, 5), DialogueData(2442, 4), DialogueData(), DialogueData() },               // MH
		{ DialogueData(2443, 3), DialogueData(2444, 5), DialogueData(2445, 3), DialogueData(), DialogueData(), DialogueData(), DialogueData() },                             // S v Sh 1
		{ DialogueData(2446, 3), DialogueData(2447, 6), DialogueData(2448, 5), DialogueData(2449, 6), DialogueData(), DialogueData(), DialogueData() },                      // GF
		{ DialogueData(2450, 4), DialogueData(2451, 7), DialogueData(2452, 4), DialogueData(2453, 4), DialogueData(), DialogueData(), DialogueData() },                      // PH
		} };
};
