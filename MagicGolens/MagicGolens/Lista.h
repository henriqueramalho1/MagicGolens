#pragma once
using namespace IdsCol;

template<class TL>
class Lista
{
public:

	Lista();
	~Lista();
	void incluirInfo(TL* info);
	void removerInfo(TL* info);
	void removerDestruir(TL* info);
	void esvaziar();
	TL* voltarInicio();
	TL* irProximo();

private:

	template<class TE>
	class Elemento
	{
	private:
		Elemento<TE>* pProx;
		Elemento<TE>* pAnt;
		TE* pInfo;

	public:
		Elemento();
		~Elemento();
		void setpProx(Elemento<TE>* next);
		Elemento<TE>* getpProx() { return pProx; };
		void setpAnt(Elemento<TE>* previous);
		Elemento<TE>* getpAnt() { return pAnt; };
		void setInfo(TE* info);
		TE* getInfo() { return pInfo; };
	};

	Elemento<TL>* pPrim;
	Elemento<TL>* pFim;
	Elemento<TL>* pAtual;
};

//Funcoes classe Elemento

template<class TL>
template<class TE>
Lista<TL>::Elemento<TE>::Elemento()
{
	pProx = NULL;
	pAnt = NULL;
	pInfo = NULL;
}

template<class TL>
template<class TE>
Lista<TL>::Elemento<TE>::~Elemento()
{
	pProx = NULL;
	pAnt = NULL;
	pInfo = NULL;
}

template<class TL>
template<class TE>
void Lista<TL>::Elemento<TE>::setpProx(Elemento<TE>* next)
{
	pProx = next;
}

template<class TL>
template<class TE>
void Lista<TL>::Elemento<TE>::setpAnt(Elemento<TE>* previous)
{
	pAnt = previous;
}

template<class TL>
template<class TE>
void Lista<TL>::Elemento<TE>::setInfo(TE* info)
{
	if (info != NULL)
	{
		pInfo = info;
	}
	else
	{
		cout << "ERRO: Nao foi possivel setar info ao elemento pois o ponteiro eh nulo" << endl;
		exit(90);
	}
}

//Funcoes classe Lista

template<class TL>
Lista<TL>::Lista()
{
	pPrim = NULL;
	pFim = NULL;
	pAtual = NULL;
}

template<class TL>
Lista<TL>::~Lista()
{
}

template<class TL>
void Lista<TL>::incluirInfo(TL* info)
{
	if (info != NULL)
	{
		Elemento<TL>* pAux = new Elemento<TL>();
		pAux->setInfo(info);

		if (pPrim == NULL)
		{
			pPrim = pAux;
			pFim = pPrim;
		}
		else
		{
			pFim->setpProx(pAux);
			pAux->setpAnt(pFim);
			pFim = pAux;
		}
	}
	else
	{
		cout << "ERRO: Ponteiro recebido para ser inserido na lista eh nulo" << endl;
		exit(48);
	}
}

template<class TL>
void Lista<TL>::removerInfo(TL* info)
{
	Elemento<TL>* pAux = pPrim;

	while (pAux->getInfo() != info)
	{
		pAux = pAux->getpProx();
	}

	if (pAux == pPrim)
	{
		pPrim = pAux->getpProx();
		if(pPrim != NULL)
			pPrim->setpAnt(NULL);
	}
	else if (pAux == pFim)
	{
		pFim = pFim->getpAnt();
		pFim->setpProx(NULL);
	}
	else
	{
		pAux->getpAnt()->setpProx(pAux->getpProx());
		pAux->getpProx()->setpAnt(pAux->getpAnt());
	}

	delete pAux;
}

template<class TL>
void Lista<TL>::removerDestruir(TL* info)
{
	Elemento<TL>* pAux = pPrim;
	TL* pInfo = NULL;

	while (pInfo != info)
	{
		pAux = pAux->getpProx();
		pInfo = pAux->getInfo();
	}

	if (pAux == pPrim)
	{
		pPrim = pAux->getpProx();
		if (pPrim != NULL)
			pPrim->setpAnt(NULL);
	}
	else if (pAux == pFim)
	{
		pFim = pFim->getpAnt();
		pFim->setpProx(NULL);
	}
	else
	{
		pAux->getpAnt()->setpProx(pAux->getpProx());
		pAux->getpProx()->setpAnt(pAux->getpAnt());
	}

	delete pInfo;
	delete pAux;
}

template<class TL>
void Lista<TL>::esvaziar()
{
	Elemento<TL>* pAux = pPrim;

	while (pAux != NULL)
	{
		pPrim = pAux->getpProx();
		delete pAux;
		pAux = pPrim;
	}

	pPrim = NULL;
	pFim = NULL;
	pAtual = NULL;
}

template<class TL>
TL* Lista<TL>::voltarInicio()
{
	pAtual = pPrim;

	if (pAtual != NULL)
	{
		return pPrim->getInfo();
	}

	cout << "ERRO: pPrim = NULL" << endl;
	return NULL;
}

template<class TL>
TL* Lista<TL>::irProximo()
{
	pAtual = pAtual->getpProx();

	if (pAtual != NULL)
		return pAtual->getInfo();
	else
	{
		return NULL;
	}
}