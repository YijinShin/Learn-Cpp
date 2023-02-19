#pragma once
class CStore
{
private:
	STOREINFO m_stStoreInfo;
public:
	CStore();
	~CStore();

	void Initialize();
	void Update();
	void Release();

	void SetType(int _iType);
	void SellMenu();
	void BuyMenu();

	void ShowItemList();
	void Sell();
	void Buy(int _iItem);

	void ClearItemList();

};

