#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"
#include "Animation.h"
#include "BulletManager.h"
#include "Health.h"
#include <random>

class Boss
{
public:
	enum State
	{
		EntranceState, AliveState, ExplodingState, DeadState
	};
	Boss(AnimationFrames& bossAnim, BulletManager& LeftBulletM, BulletManager& RightBulletM, BulletManager& CenterBulletM,
		AnimationFrames& BulletAnim, AnimationFrames& lightBallAnim, AnimationFrames& bossExploAnim, AnimationFrames& bossPreExploAnim);
	void Update(float dt, float playerPos);
	void Draw(Graphics& gfx);
	RectF GetBottomCollisionRect() const;
	RectF GetTopCollisionRect() const;
	RectF GetLeftCollisionRect() const;
	RectF GetRightCollisionRect() const;
	RectF GetCollisionRect() const;
	int GetCollisionDmg() const;
	void Attack(float dt, float playerPos, short choice);
	void Thrust(float dt, float playerPos);
	void BulletSpread(float dt, float playerPos);
	void Missile(float dt, float playerPos);
	void Move(float dt, float playerPos);
	void HandleCollision(int dmg);
	bool GetCoolDown() const;
	bool IsEntering() const;
	bool IsAliveState() const;
	float GetLeft() const;
	float GetRight() const;
	float GetTop() const;
	float GetBottom() const;
	void BringBack(float dt);
	void BringToCenter(float dt);
	bool IsExploding() const;

	void Reset();

private:
	Vec2 pos = Vec2(315.0f, -250.0f);
	Vec2 vel = Vec2(100.0f, 100.0f);
	Vec2 midPoint = Vec2(400.0f, 140.0f);
	Vec2 screenCenter = Vec2(400.0f, 300.0f);
	Vec2 bossCenter;
	float attackTimer = 0.0f;
	float attack = 1.0f;
	float specialAttackTimer = 0.0f;
	float specialAttack = 5.0f;
	float lightBallTimer = 0.0f;
	float fireLightball = 0.3f;
	int lightBallCounter = 0;
	float lightBallDir = -400.0f;
	bool isAttacking = false;
	bool attackOver = false;
	bool hasPlayerPos = false;
	Vec2 leftCanon = Vec2(25.0f, 200.0f);
	Vec2 rightCanon = Vec2(90.0f, 200.0f);
	Vec2 centerCanon = Vec2(57.5f, 220.0f);
	Vec2 bulletVel = Vec2(0.0f, -300.0f);
	static constexpr int bulletHalfWidth = 30;
	static constexpr int bulletHalfHeight = 37;
	static constexpr int bulletRectSize = 15;
	static constexpr float bulletPitch = 0.3f;
	static constexpr float entranceSpeed = 50.0f;
	static constexpr float width = 170.0f;
	static constexpr float height = 250.0f;
	static constexpr int collisionDmg = 75;
	static constexpr int bulletDmg = 50;
	Animation bossSprite;
	Animation lightBall;
	BulletManager& leftBulletM;
	BulletManager& rightBulletM;
	BulletManager& centerBulletM;
	Animation bulletSprite;
	State state = EntranceState;
	bool coolDown = false;
	float coolDownTimer = 0.0f;
	static constexpr float coolDownOver = 0.75f;
	int hp = 300;
	int healthX = 475;
	int healthY = 20;
	float thrustY = 300.0f;
	float thrustX;
	float thrustLeft = -300.0f;
	float thrustRight = 300.0f;
	Health health;
	bool choiceWasMade = false;
	short AttackChoice;
	float lightBallIncrement;
	Animation bossExplo;
	Animation bossPreExplo;
	bool isNotExploding = true;
	int exploCounter = 0;
};

