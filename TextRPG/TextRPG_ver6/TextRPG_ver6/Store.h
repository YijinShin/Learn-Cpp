#pragma once
class CPlayer;

class CStore
{
private:
	STOREINFO m_stStoreInfo;
	CPlayer* m_cpPlayer;
public:
	CStore();
	~CStore();

	void Initialize(CPlayer* _cpPlayer);
	void Update();
	void Release();

	void SetType(int _iType);
	void SellMenu();
	void BuyMenu();

	void ShowItemList();
	void Sell(int _iItemId);
	void Buy(int _iItemId);

	void ClearItemList();
};

