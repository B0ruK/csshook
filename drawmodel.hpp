
void OverridematerialXQZ(Material* mat, float r, float g, float b)
{
	mat->SetFlag(IGNOREZ, true);

	float Color[3] = { r / 255, g / 255, b / 255 };

	pRenderView->SetColorModulation(Color);
	pModelRender->ForcedMaterialOverride(mat);
}

void Overridematerial(Material* mat, float r, float g, float b)
{
	mat->SetFlag(IGNOREZ, false);

	float Color[3] = { r / 255, g / 255, b / 255 };

	pRenderView->SetColorModulation(Color);
	pModelRender->ForcedMaterialOverride(mat);
}

typedef void(__thiscall *DrawModelExecuteFn)(ModelRender*, void*, const ModelRenderInfo&, void*);
DrawModelExecuteFn draw_model_original = nullptr;

void __stdcall hkDrawModelExecute(void* state, const ModelRenderInfo &pInfo, void *bonetoworld)
{
	static Material* material = pMaterialSystem->FindMaterial("debug/debugambientcube", "Model textures");

	if (pInfo.entity_index && material)
	{
		Entities* pEntity = (Entities*)pEntList->GetClientEntity(pInfo.entity_index);
		Entities *pLocal = pEntList->GetClientEntity(pEngine->GetLocalPlayer());

		if (gCvars.bMenu)
		{
			material->SetFlag(ZNEARER, true);
			material->SetFlag(NOCULL, true);
			material->SetFlag(NOFOG, true);
			material->SetFlag(HALFLAMBERT, true);
		}

		if (pEntity && pLocal && material)
		{
			if ((gCvars.CHAMTEAM || pEntity->GetTeamNum() != pLocal->GetTeamNum()) && gCvars.chams)
			{
				if (pEntity->IsAlive() && pEntity->IsPlayer())
				{
					if (gCvars.XQZ)
					{
						OverridematerialXQZ(material, gCvars.colorsredFIVE, gCvars.colorsgreenFIVE, gCvars.colorsblueFIVE);
						draw_model_original(pModelRender, state, pInfo, bonetoworld);
					}
					Overridematerial(material, gCvars.colorsredFOUR, gCvars.colorsgreenFOUR, gCvars.colorsblueFOUR);
				}
			}
		}
	}

	draw_model_original(pModelRender, state, pInfo, bonetoworld);
	pModelRender->ForcedMaterialOverride(nullptr);
}