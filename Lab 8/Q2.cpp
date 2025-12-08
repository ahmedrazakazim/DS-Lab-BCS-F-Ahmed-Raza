#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

// --- Combatant Data Structure (Replacing string and BST Node) ---
struct Combatant {
    string name;
    int keyID;
    int health;
    int attack;
    Combatant(string n, int id, int hp, int atk) : name(n), keyID(id), health(hp), attack(atk) {}
};

class BattleNode {
public:
    Combatant data;
    BattleNode* left;
    BattleNode* right;

    BattleNode(string n, int id, int hp, int atk) : data(n, id, hp, atk) {
        left = NULL;
        right = NULL;
    }
    
    // Destructor for cleanup
    ~BattleNode() {
        delete left;
        delete right;
    }
};

// --- Reused BST Methods ---

BattleNode* insertNode(BattleNode* root, Combatant c) {
    if (root == NULL) {
        return new BattleNode(c.name, c.keyID, c.health, c.attack);
    }
    if (c.keyID < root->data.keyID) {
        root->left = insertNode(root->left, c);
    } else if (c.keyID > root->data.keyID) {
        root->right = insertNode(root->right, c);
    }
    return root;
}

BattleNode* findMinNode(BattleNode* node) {
    BattleNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

BattleNode* deleteNode(BattleNode* root, int keyID) {
    if (root == NULL) {
        return root;
    }

    if (keyID < root->data.keyID) {
        root->left = deleteNode(root->left, keyID);
    } else if (keyID > root->data.keyID) {
        root->right = deleteNode(root->right, keyID);
    } else {
        if (root->left == NULL) {
            BattleNode* temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BattleNode* temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        }

        BattleNode* temp = findMinNode(root->right);

        root->data.name = temp->data.name;
        root->data.keyID = temp->data.keyID;
        root->data.health = temp->data.health;
        root->data.attack = temp->data.attack;

        root->right = deleteNode(root->right, temp->data.keyID);
    }
    return root;
}

// --- Game Specific Methods ---

void displayTeam(BattleNode* root) {
    if (root != NULL) {
        displayTeam(root->left);
        cout << "(" << root->data.name << " HP:" << root->data.health << ") ";
        displayTeam(root->right);
    }
}

BattleNode* getFrontline(BattleNode* root) {
    return findMinNode(root);
}

int calculateDamage(int baseAttack) {
    return baseAttack + (rand() % 5);
}

void battleLoop(BattleNode*& playerTree, BattleNode*& enemyTree) {
    int round = 1;

    while (playerTree != NULL && enemyTree != NULL) {
        cout << "\n---------------------------------------------------" << endl;
        cout << "ROUND: " << round << endl;
        
        cout << "HERO TEAM: ";
        displayTeam(playerTree);
        cout << endl;
        
        cout << "ENEMY TEAM: ";
        displayTeam(enemyTree);
        cout << endl;

        // Player's Turn
        BattleNode* playerAttacker = getFrontline(playerTree);
        BattleNode* enemyDefender = getFrontline(enemyTree);

        cout << "\nPlayer Turn: " << playerAttacker->data.name << " attacks " << enemyDefender->data.name << endl;
        
        int damage = calculateDamage(playerAttacker->data.attack);
        int oldHP = enemyDefender->data.health;
        enemyDefender->data.health -= damage;
        
        cout << "Damage dealt: " << damage << endl;
        cout << enemyDefender->data.name << " HP: " << oldHP << " -> " << enemyDefender->data.health << endl;

        if (enemyDefender->data.health <= 0) {
            int defeatedID = enemyDefender->data.keyID;
            string defeatedName = enemyDefender->data.name;
            
            enemyTree = deleteNode(enemyTree, defeatedID);
            
            cout << "\n*** ELIMINATION: " << defeatedName << " was defeated! ***" << endl;
            if (enemyTree == NULL) break;
            cout << getFrontline(enemyTree)->data.name << " is the new enemy frontline!" << endl;
        }
        
        // Enemy's Turn (only if both teams are still standing)
        if (playerTree != NULL && enemyTree != NULL) {
            playerAttacker = getFrontline(playerTree); // May have changed if player was just eliminated, but here it's still the player's team
            enemyDefender = getFrontline(enemyTree); // May have changed if enemy was just eliminated
            
            BattleNode* enemyAttacker = enemyDefender;
            BattleNode* playerDefender = playerAttacker;

            cout << "\nEnemy Turn: " << enemyAttacker->data.name << " attacks " << playerDefender->data.name << endl;
            
            damage = calculateDamage(enemyAttacker->data.attack);
            oldHP = playerDefender->data.health;
            playerDefender->data.health -= damage;
            
            cout << "Damage dealt: " << damage << endl;
            cout << playerDefender->data.name << " HP: " << oldHP << " -> " << playerDefender->data.health << endl;

            if (playerDefender->data.health <= 0) {
                int defeatedID = playerDefender->data.keyID;
                string defeatedName = playerDefender->data.name;
                
                playerTree = deleteNode(playerTree, defeatedID);
                
                cout << "\n*** ELIMINATION: " << defeatedName << " was defeated! ***" << endl;
                if (playerTree == NULL) break;
                cout << getFrontline(playerTree)->data.name << " is the new hero frontline!" << endl;
            }
        }
        
        round++;
    }

    cout << "\n===================================================" << endl;
    if (playerTree == NULL) {
        cout << "VICTORY: The Enemy Team wins the BattleQuest!" << endl;
    } else {
        cout << "VICTORY: The Hero Team wins the BattleQuest!" << endl;
    }
    cout << "===================================================" << endl;
    
    // Cleanup to prevent memory leak
    delete playerTree;
    delete enemyTree;
}

int main() {
    srand(time(0));
    
    BattleNode* playerTeam = NULL;
    BattleNode* enemyTeam = NULL;

    // Player Initialization (Name, ID, HP, ATK)
    playerTeam = insertNode(playerTeam, Combatant("Kael", 101, 100, 15));
    playerTeam = insertNode(playerTeam, Combatant("Lira", 105, 90, 20));
    playerTeam = insertNode(playerTeam, Combatant("Grom", 103, 120, 12));
    playerTeam = insertNode(playerTeam, Combatant("Sena", 104, 80, 25));
    playerTeam = insertNode(playerTeam, Combatant("Rix", 102, 110, 18));

    // Enemy Initialization (Name, ID, HP, ATK)
    enemyTeam = insertNode(enemyTeam, Combatant("Goblin", 201, 80, 10));
    enemyTeam = insertNode(enemyTeam, Combatant("Orc", 205, 110, 15));
    enemyTeam = insertNode(enemyTeam, Combatant("Troll", 203, 150, 8));
    enemyTeam = insertNode(enemyTeam, Combatant("Witch", 204, 70, 22));
    enemyTeam = insertNode(enemyTeam, Combatant("Vamp", 202, 95, 17));

    battleLoop(playerTeam, enemyTeam);

    return 0;
}
