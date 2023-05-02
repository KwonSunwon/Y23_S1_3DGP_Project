#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"

CScene::CScene(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

CScene::~CScene()
{
}

void CScene::BuildObjects()
{
	//CExplosiveObject::PrepareExplosion();

	float fHalfWidth = 45.0f, fHalfHeight = 45.0f, fHalfDepth = 200.0f;
	CFloorMesh* pFloorMesh = new CFloorMesh(fHalfWidth * 2.0f, fHalfDepth * 2.0f, 30);

	m_pFloorObject = new CFloorObject();
	m_pFloorObject->SetPosition(0.0f, 0.0f, 0.0f);
	m_pFloorObject->SetMesh(pFloorMesh);
	m_pFloorObject->SetColor(RGB(0, 0, 0));
	m_pFloorObject->m_pxmf4FloorPlane = XMFLOAT4(0.0f, +1.0f, 0.0f, 0.0f);

	CCubeMesh* pCubeMesh = new CCubeMesh(10.0f, 5.0f, 4.0f);

	// 두 번째 플레이어
	CTankPlayer* aotherPlayer = new CTankPlayer();
	aotherPlayer->SetPosition(10.0f, 1.0f, 0.0f);
	aotherPlayer->SetCamera(nullptr);
	aotherPlayer->SetCameraOffset(XMFLOAT3(0.0f, 5.0f, -15.0f));
	addObject(aotherPlayer);

	CWallObject* pWallObject = new CWallObject();
	pWallObject->SetMesh(pCubeMesh);
	pWallObject->SetColor(RGB(255, 0, 0));
	pWallObject->SetPosition(40.0f, 2.5f, 0.0f);
	addObject(pWallObject);

	pWallObject = new CWallObject();
	pWallObject->SetMesh(pCubeMesh);
	pWallObject->SetColor(RGB(0, 0, 255));
	pWallObject->SetPosition(-20.0f, 2.5f, 0.0f);
	addObject(pWallObject);

	/*CCubeMesh* pCubeMesh = new CCubeMesh(4.0f, 4.0f, 4.0f);

	m_nObjects = 10;
	m_ppObjects = new CGameObject * [m_nObjects];

	CExplosiveObject* pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-43.5f, 0.0f, -44.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppObjects[0] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(0, 0, 255));
	pExplosiveObject->SetPosition(+43.5f, 0.0f, -44.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(180.0f);
	m_ppObjects[1] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(0, 255, 0));
	pExplosiveObject->SetPosition(-43.5f, 0.0f, +44.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(30.15f);
	m_ppObjects[2] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(0, 255, 255));
	pExplosiveObject->SetPosition(+43.5f, 0.0f, +44.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(40.6f);
	m_ppObjects[3] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(128, 0, 255));
	pExplosiveObject->SetPosition(0.0f, 0.0f, 40.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(50.06f);
	m_ppObjects[4] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 255));
	pExplosiveObject->SetPosition(-20.0f, 0.0f, -20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(60.06f);
	m_ppObjects[5] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 255));
	pExplosiveObject->SetPosition(-20.0f, 0.0f, +20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(60.06f);
	m_ppObjects[6] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 128));
	pExplosiveObject->SetPosition(+20.0f, 0.0f, -20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(70.06f);
	m_ppObjects[7] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(128, 0, 255));
	pExplosiveObject->SetPosition(+20.0f, 0.0f, +20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppObjects[8] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 64, 64));
	pExplosiveObject->SetPosition(+15.0f, 0.0f, 0.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppObjects[9] = pExplosiveObject;*/

#ifdef _WITH_DRAW_AXIS
	m_pWorldAxis = new CGameObject();
	CAxisMesh* pAxisMesh = new CAxisMesh(0.5f, 0.5f, 0.5f);
	m_pWorldAxis->SetMesh(pAxisMesh);
#endif
}

void CScene::ReleaseObjects()
{
	if (CExplosiveObject::m_pExplosionMesh) CExplosiveObject::m_pExplosionMesh->Release();

	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete m_ppObjects[i];
	//if (m_ppObjects) delete[] m_ppObjects;
	m_ppObjects.clear();

	if (m_pFloorObject) delete m_pFloorObject;

#ifdef _WITH_DRAW_AXIS
	if (m_pWorldAxis) delete m_pWorldAxis;
#endif
}

void CScene::addObject(CGameObject* object)
{
	m_ppObjects.push_back(object);
	m_nObjects++;
}

CPlayer* CScene::PlayerChange()
{
	CPlayer* temp = m_pPlayer;
	m_pPlayer = (CPlayer*)m_ppObjects[0];
	m_pPlayer->SetCamera(temp->GetCamera());
	m_ppObjects[0] = temp;
	((CPlayer*)m_ppObjects[0])->SetCamera(nullptr);
	return m_pPlayer;
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID) {
	case WM_KEYDOWN:
		switch (wParam) {
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[int(wParam - '1')];
			pExplosiveObject->m_bBlowingUp = true;
			break;
		}
		case 'A':
			for (int i = 0; i < m_nObjects; i++) {
				CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
				pExplosiveObject->m_bBlowingUp = true;
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

CGameObject* CScene::PickObjectPointedByCursor(int xClient, int yClient, CCamera* pCamera)
{
	XMFLOAT3 xmf3PickPosition;
	xmf3PickPosition.x = (((2.0f * xClient) / (float)pCamera->m_Viewport.m_nWidth) - 1) / pCamera->m_xmf4x4PerspectiveProject._11;
	xmf3PickPosition.y = -(((2.0f * yClient) / (float)pCamera->m_Viewport.m_nHeight) - 1) / pCamera->m_xmf4x4PerspectiveProject._22;
	xmf3PickPosition.z = 1.0f;

	XMVECTOR xmvPickPosition = XMLoadFloat3(&xmf3PickPosition);
	XMMATRIX xmmtxView = XMLoadFloat4x4(&pCamera->m_xmf4x4View);

	int nIntersected = 0;
	float fNearestHitDistance = FLT_MAX;
	CGameObject* pNearestObject = NULL;
	for (int i = 0; i < m_nObjects; i++) {
		float fHitDistance = FLT_MAX;
		nIntersected = m_ppObjects[i]->PickObjectByRayIntersection(xmvPickPosition, xmmtxView, &fHitDistance);
		if ((nIntersected > 0) && (fHitDistance < fNearestHitDistance)) {
			fNearestHitDistance = fHitDistance;
			pNearestObject = m_ppObjects[i];
		}
	}
	return(pNearestObject);
}

void CScene::CheckObjectByObjectCollisions()
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->m_pObjectCollided = NULL;
	for (int i = 0; i < m_nObjects; i++) {
		for (int j = (i + 1); j < m_nObjects; j++) {
			if (m_ppObjects[i]->m_xmOOBB.Intersects(m_ppObjects[j]->m_xmOOBB)) {
				m_ppObjects[i]->m_pObjectCollided = m_ppObjects[j];
				m_ppObjects[j]->m_pObjectCollided = m_ppObjects[i];
			}
		}
	}
	for (int i = 0; i < m_nObjects; i++) {
		if (m_ppObjects[i]->m_pObjectCollided) {
			XMFLOAT3 xmf3MovingDirection = m_ppObjects[i]->m_xmf3MovingDirection;
			float fMovingSpeed = m_ppObjects[i]->m_fMovingSpeed;
			m_ppObjects[i]->m_xmf3MovingDirection = m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection;
			m_ppObjects[i]->m_fMovingSpeed = m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection = xmf3MovingDirection;
			m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed = fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_pObjectCollided = NULL;
			m_ppObjects[i]->m_pObjectCollided = NULL;
		}
	}
}

void CScene::CheckObjectByBulletCollisions()
{
	CBulletObject** ppBullets = ((CTankPlayer*)m_pPlayer)->m_ppBullets;
	for (int i = 0; i < m_nObjects; i++) {
		for (int j = 0; j < BULLETS; j++) {
			if (ppBullets[j]->m_bActive && m_ppObjects[i]->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB)) {
				//CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
				//pExplosiveObject->m_bBlowingUp = true;
				//ppBullets[j]->Reset();

				BoundingOrientedBox collisionOOBB = m_ppObjects[i]->m_xmOOBB;
				// oobb 의 회전각도 
				XMVECTOR quat = XMLoadFloat4(&collisionOOBB.Orientation);
				// oobb 의 회전각도를 이용하여 forward, right, up 벡터를 구함
				XMVECTOR forward = (XMVector3Rotate(XMVectorSet(0, 0, 1, 0), quat));
				XMVECTOR right = (XMVector3Rotate(XMVectorSet(1, 0, 0, 0), quat));
				XMVECTOR up = (XMVector3Rotate(XMVectorSet(0, 1, 0, 0), quat));

				// oobb 의 너비, 높이, 깊이
				float width = collisionOOBB.Extents.x;
				float height = collisionOOBB.Extents.y;
				float depth = collisionOOBB.Extents.z;

				// oobb 의 중심점
				XMVECTOR center = XMLoadFloat3(&collisionOOBB.Center);

				XMVECTOR plane[6];
				plane[0] = XMPlaneFromPointNormal(center - forward * depth, -forward);
				plane[1] = XMPlaneFromPointNormal(center + forward * depth, forward);
				plane[2] = XMPlaneFromPointNormal(center - right * width, -right);
				plane[3] = XMPlaneFromPointNormal(center + right * width, right);
				plane[4] = XMPlaneFromPointNormal(center - up * height, -up);
				plane[5] = XMPlaneFromPointNormal(center + up * height, up);

				BoundingOrientedBox bulletOOBB = ppBullets[j]->m_xmOOBB;
				for (int i = 0; i < 6; ++i) {
					if (bulletOOBB.Intersects(plane[i]) == INTERSECTING) {
						XMVECTOR planeNormal = { plane[i].m128_f32[0], plane[i].m128_f32[1], plane[i].m128_f32[2] };
						XMVECTOR bulletDirection = XMLoadFloat3(&ppBullets[j]->m_xmf3MovingDirection);
						XMVECTOR reflectionDirection = XMVector3Reflect(bulletDirection, planeNormal);
						XMStoreFloat3(&ppBullets[j]->m_xmf3MovingDirection, reflectionDirection);
						break;
					}
				}

				// 벽에 총알이 충돌하면 반사각을 계산해 튕겨져 나오는건 구현완료되었는데
				// 애매한 위치에 총알이 충돌하거나 정상적으로 작동해야할 각도인데도 이상한 방향으로 반사각이 계산되는 경우가 있음
				// 또한 튕긴 후의 방향이 벽을 통과하는 방향이 되어 이상하게 날아가는 경우도 발생
				// 5.2 7:49
				// 총알의 속도를 절반으로 해서 테스트를 진행해 봤는데 기존의 높은 속도가 충돌 판정을 하는 데 있어
				// 제대로된 결과를 주지 못한게 아닌가 하는 생각이 들었음.
				// 그리고 속도를 낮췄음에도 불구하고 여전히 이상한 방향으로 튕겨져 나가는 경우가 있음(모서리에 맞추는 경우)
				// 면에 정확히 맞는 경우에 이상한 방향으로 튕겨져 나가는 경우는 줄어든거 같음
			}

		}
	}
}

void CScene::CheckObjectByPlayerCollisions()
{
	for (int i = 0; i < m_nObjects; ++i) {
		if (m_ppObjects[i]->m_xmOOBB.Intersects(m_pPlayer->m_xmOOBB))
			m_pPlayer->OnCollisionByWall();
	}
}

void CScene::Animate(float fElapsedTime)
{
	m_pFloorObject->Animate(fElapsedTime);
	m_pFloorObject->ComputeWorldTransform(NULL);
	/*수정*/
	for (int i = 0; i < m_nObjects; i++) {
		m_ppObjects[i]->Animate(fElapsedTime);
		m_ppObjects[i]->ComputeWorldTransform(NULL);
		m_ppObjects[i]->UpdateBoundingBox();
	}

	CheckObjectByObjectCollisions();
	CheckObjectByBulletCollisions();

	CheckObjectByPlayerCollisions();
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGraphicsPipeline::SetViewport(&pCamera->m_Viewport);
	CGraphicsPipeline::SetViewPerspectiveProjectTransform(&pCamera->m_xmf4x4ViewPerspectiveProject);

	m_pFloorObject->Render(hDCFrameBuffer, pCamera);
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);

	if (m_pPlayer) m_pPlayer->Render(hDCFrameBuffer, pCamera);

	//UI
#ifdef _WITH_DRAW_AXIS
	CGraphicsPipeline::SetViewOrthographicProjectTransform(&pCamera->m_xmf4x4ViewOrthographicProject);
	m_pWorldAxis->SetRotationTransform(&m_pPlayer->m_xmf4x4World);
	m_pWorldAxis->Render(hDCFrameBuffer, pCamera);
#endif
}
