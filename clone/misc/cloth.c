// cloth.c
// writed by shadow
// This is the basic equip for players just login.

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	object ob;
	mapping fam;
	int shen;
	int budd;

	set_name("����", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
        	set_default_object(__FILE__);
	else {
	        set("unit", "��");
	        set("material", "cloth");
	        set("armor_prop/armor", 1);
	}

	ob=this_player();

	if ( ob->query("gender") == "Ů��" )
	{
		set("female_only", 1);
	}

	if( ob->is_ghost() )
	{
//		return HIB "�� ��  �� ��" NOR;
		switch (random(2))
		{
			case 0:set_name(BLK "��ɫɥ��" NOR, ({"black cloth","cloth"}));break;
			case 1:set_name(HIW "��ɫɥ��" NOR, ({"white cloth","cloth"}));break;
		}
	}

	shen = ob->query("shen");
	if ( (fam = ob->query("family")) && fam["family_name"] == "������" )
		budd = ob->query_skill("buddhism",1);

	switch(ob->query("gender"))
	{
		case "Ů��":
			switch(wizhood(ob))
			{
				case "(admin)":
//					return HIW "�� Ů  �� ��" NOR;
					switch (random(2))
					{
case 0:set_name(WHT "��������" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(HIM "�������" NOR, ({"pink cloth","cloth"}));break;
					}
					break;
				case "(sage)":
//					return HIW "�� Ů  �� ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "ǳ������" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(WHT "��������" NOR, ({"pink cloth","cloth"}));break;
					}
					break;
					
				case "(arch)":
//					return HIY "�� ����Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "��������" NOR, ({"purple cloth","cloth"}));break;
case 1:set_name(HIM "�������" NOR, ({"pink cloth","cloth"}));break;
					}
					break;
				case "(angel)":
//					return HIG "�� ��  Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(HIY "�������" NOR, ({"black cloth","cloth"}));break;
case 1:set_name(HIG "��������" NOR, ({"green cloth","cloth"}));break;
					}
					break;
					
				case "(wizard)":
//					return HIG "�� ��  Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(HIY "�������" NOR, ({"black cloth","cloth"}));break;
case 1:set_name(HIG "��������" NOR, ({"green cloth","cloth"}));break;
					}
					break;
				case "(apprentice)":
//					return HIC "�� С��Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "��ɫ��ɴ" NOR, ({"purple cloth","cloth"}));break;
case 1:set_name(HIM "�����ɴ" NOR, ({"pink cloth","cloth"}));break;
					}
					break;
				case "(genie)":
//					return HIC "�� С��Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "��ɫ��ɴ" NOR, ({"purple cloth","cloth"}));break;
case 1:set_name(HIM "�����ɴ" NOR, ({"pink cloth","cloth"}));break;
					}
					break;
					
				case "(immortal)":
//					return HIC "�� ��  Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "��������" NOR, ({"purple cloth","cloth"}));break;
case 1:set_name(HIM "�������" NOR, ({"pink cloth","cloth"}));break;
					}
					break;
				default:
					if ( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					{
//						return HIR "��Ůɱ��ħ��" NOR;
						switch (random(1))
						{
case 0:set_name(RED "ԡѪս��" NOR, ({"read cloth","cloth"}));break;
						}
					}
					if( (int)ob->query("thief") > 10 )
					{
//						return HIW "��Ů �� �ԡ�" NOR;
						switch (random(1))
						{
case 0:set_name(HIB "��ɫƤȹ" NOR, ({"black skirt","skirt"}));break;
						}
					}
					if (shen >= 1000000)
					{
//						return HIC "������Ů����" NOR;
						switch (random(3))
						{
case 0:set_name(RED "���ս��" NOR, ({"red cloth","cloth"}));break;
case 1:set_name(HIY "��ɫ��ɴ" NOR, ({"yellow skirt","skirt"}));break;
case 2:set_name(BLK "��ɫս��" NOR, ({"black cloth","cloth"}));break;
						}
					}
					else if (shen >= 100000)
					{
//						return HIC "�� Ů���� ��" NOR;
						switch (random(3))
						{
case 0:set_name(YEL "ǳ�Ƴ�ȹ" NOR, ({"yellow skirt","skirt"}));break;
case 1:set_name(MAG "��ɴ����" NOR, ({"purple cloth","cloth"}));break;
case 2:set_name(HIG "��ɫ����" NOR, ({"green cloth","cloth"}));break;
						}
					}
					else if (shen >= 10000)
					{
//						return HIC "�� Ů  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(HIW "��ɫ�ͷ�" NOR, ({"white skirt","skirt"}));break;
case 1:set_name(MAG "ǳ����ɴ" NOR, ({"purple cloth","cloth"}));break;
case 2:set_name(BLK "��ɫ��װ" NOR, ({"black cloth","cloth"}));break;
						}
					}
					else if (shen >= 1000)
					{
//						return HIC "�� Ů���� ��" NOR;
						switch (random(3))
						{
case 0:set_name(CYN "��ɫ����" NOR, ({"green cloth","cloth"}));break;
case 1:set_name(MAG "ǳ����ɴ" NOR, ({"purple skirt","skirt"}));break;
case 2:set_name(GRN "����С��" NOR, ({"green cloth","cloth"}));break;
						}
					}
					else if (shen <= -1000000)
					{
//						return HIR "�� Ůħ�� ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "���ս��" NOR, ({"red cloth","cloth"}));break;
case 1:set_name(MAG "ǳ�ϱ�ɴ" NOR, ({"purple skirt","skirt"}));break;
case 2:set_name(BLK "��ɫҹ����" NOR, ({"black cloth","cloth"}));break;
						}
					}
					else if (shen <= -100000)
					{
//						return HIR "�� Ů��ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(WHT "��ɫս��" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(CYN "��ɫɴȹ" NOR, ({"green skirt","skirt"}));break;
case 2:set_name(BLK "��ɫ����" NOR, ({"black cloth","cloth"}));break;
						}
					}
					else if (shen <= -10000)
					{
//						return HIR "�� Ů  ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "�������" NOR, ({"red cloth","cloth"}));break;
case 1:set_name(MAG "ǳ����ɴ" NOR, ({"purple cloth","cloth"}));break;
case 2:set_name(HIC "��ɫ����" NOR, ({"green skirt","skirt"}));break;
						}
					}
					else if (shen <= -1000)
					{
//						return HIR "�� Ů��ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "���ս��" NOR, ({"red cloth","cloth"}));break;
case 1:set_name(MAG "ǳ����ɴ" NOR, ({"purple cloth","cloth"}));break;
case 2:set_name(GRN "��ɫ��ȹ" NOR, ({"green skirt","skirt"}));break;
						}
					}
					else
						switch(ob->query("class"))
						{
							case "bonze":
//								return "�� ��  �� ��";
								switch (random(2))
								{
case 0:set_name(NOR "��ɫɮ��" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(YEL "����ɫɮ��" NOR, ({"yellow cloth","cloth"}));break;
								}
								break;
							case "taoist":
//								return "�� Ů  �� ��";
								switch (random(2))
								{
case 0:set_name(NOR "��ɫ����" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(YEL "����ɫ����" NOR, ({"yellow cloth","cloth"}));break;
								}
								break;
							case "shashou":
//								return HIY "��Ů ɱ �֡�" NOR;
								switch (random(2))
								{
case 0:set_name(GRN "��ɫ�й�" NOR, ({"green cloth","cloth"}));break;
case 1:set_name(HIC "��ɫɴȹ" NOR, ({"green skirt","skirt"}));break;
								}
								break;
							case "yishi":
//								return "��Ů �� ʿ��";
								switch (random(2))
								{
case 0:set_name(MAG "ǳ������" NOR, ({"purple skirt","skirt"}));break;
case 1:set_name(YEL "��ɫ����" NOR, ({"yellow cloth","cloth"}));break;
								}
								break;
							case "recruit":
//								return "�� ��  Ů ��";
								switch (random(2))
								{
case 0:set_name(WHT "��ɫ����" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(CYN "��ɫɴȹ" NOR, ({"yellow skirt","skirt"}));break;
								}
								break;
							case "bandit":
//								return "�� Ů���� ��";
								switch (random(2))
								{
case 0:set_name(BLK "��ɫҹ����" NOR, ({"black cloth","cloth"}));break;
case 1:set_name(BLU "�������" NOR, ({"blue cloth","cloth"}));break;
								}
								break;
							case "dancer":
//								return "�� ��  �� ��";
								switch (random(5))
								{
case 0:set_name(RED "Ʈ������" NOR, ({"red cloth","cloth"}));break;
case 1:set_name(MAG "��ɫ����" NOR, ({"purple cloth","cloth"}));break;
case 2:set_name(GRN "��ɫ��ȹ" NOR, ({"green cloth","cloth"}));break;
case 3:set_name(HIM "�ۺ�ɫ��ɴ" NOR, ({"pink cloth","cloth"}));break;
case 4:set_name(HIY "���ɫ����" NOR, ({"yellow cloth","cloth"}));break;
								}
								break;
							case "scholar":	
//								return "�� ��  Ů ��";
							case "officer":	
//								return "�� Ů  �� ��";
							case "fighter":	
//								return "�� Ů���� ��";
								switch (random(2))
								{
case 0:set_name(MAG "ǳ�϶���" NOR, ({"purple cloth","cloth"}));break;
case 1:set_name(YEL "��ɫ���" NOR, ({"yellow cloth","cloth"}));break;
								}
								break;
							case "swordsman":
//								return "�� Ů��ʿ ��";
							case "alchemist":
//								return "�� ��  ʿ ��";
							case "shaman":
//								return "�� ��  ҽ ��";
							case "beggar":
//								return "��Ů�л��ӡ�";
							default:
//								return "�� ��  Ů ��";
								switch (random(2))
								{
case 0:set_name(NOR "���ײ���" NOR, ({"cloth"}));break;
case 1:set_name(NOR "�ֲ���ȹ" NOR, ({"skirt"}));break;
								}
								break;
					}
			}
			break;
		default:
			switch(wizhood(ob))
			{
				case "(admin)":			
//					return HIW "�� ��  �� ��" NOR;
					switch (random(2))
					{
case 0:set_name(WHT "��������" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(YEL "�������" NOR, ({"gold cloth","cloth"}));break;
					}
					break;
				case "(sage)":			
//					return HIW "�� ��  �� ��" NOR;
					switch (random(2))
					{
case 0:set_name(WHT "��������" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(YEL "��������" NOR, ({"gold cloth","cloth"}));break;
					}
					break;
					
				case "(arch)":
//					return HIY "�� ����ʦ ��" NOR;
					switch (random(2))
					{
case 0:set_name(HIW "��������" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(HIC "��ɫ����" NOR, ({"green cloth","cloth"}));break;
					}
					break;
				case "(angel)":
//					return HIG "�� ��  ʦ ��" NOR;
					switch (random(2))
					{
case 0:set_name(BLU "��ɫ����" NOR, ({"blue cloth","cloth"}));break;
case 1:set_name(HIY "��ɫ����" NOR, ({"yellow cloth","cloth"}));break;
					}
					break;

				case "(wizard)":
//					return HIG "�� ��  ʦ ��" NOR;
					switch (random(2))
					{
case 0:set_name(BLU "��ɫ����" NOR, ({"blue cloth","cloth"}));break;
case 1:set_name(HIY "��ɫ����" NOR, ({"yellow cloth","cloth"}));break;
					}
					break;
				case "(apprentice)":
//					return HIC "����ʦѧͽ��" NOR;
					switch (random(2))
					{
case 0:set_name(BLK "�ڲ�����" NOR, ({"black cloth","cloth"}));break;
case 1:set_name(HIC "��ɫ����" NOR, ({"blue cloth","cloth"}));break;
					}
					break;
				case "(genie)":
//					return HIC "����ʦѧͽ��" NOR;
					switch (random(2))
					{
case 0:set_name(BLK "�ڲ�����" NOR, ({"black cloth","cloth"}));break;
case 1:set_name(HIC "��ɫ����" NOR, ({"blue cloth","cloth"}));break;
					}
					break;

				case "(immortal)":
//					return HIC "�� ��  �� ��" NOR;
					switch (random(2))
					{
case 0:set_name(HIC "����ɫ����" NOR, ({"purple cloth","cloth"}));break;
case 1:set_name(HIB "����ɫ����" NOR, ({"blue cloth","cloth"}));break;
					}
					break;
				default:
					if ( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					{
//						return HIR "�� ɱ��ħ ��" NOR;
						switch (random(1))
						{
case 0:set_name(HIR "Ѫ����" NOR, ({"read cloth","cloth"}));break;
						}
					}
					if( (int)ob->query("thief") > 10 )
					{
//						return HIW "�� ��  �� ��" NOR;
						switch (random(1))
						{
case 0:set_name(WHT "��Ƥ��" NOR, ({"white cloth","cloth"}));break;
						}
					}
					if (shen >= 1000000)
					{
//						return HIC "������������" NOR;
						switch (random(3))
						{
case 0:set_name(YEL "��˿����" NOR, ({"gold cloth","cloth"}));break;
case 1:set_name(CYN "�̴�װ" NOR, ({"brown cloth","cloth"}));break;
case 2:set_name(WHT "ѩ�����" NOR, ({"white cloth","cloth"}));break;
						}
					}
					else if (shen >= 100000)
					{
//						return HIC "�� ��  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "Ѫɫս��" NOR, ({"red cloth","cloth"}));break;
case 1:set_name(HIG "��ɫ�ͷ�" NOR, ({"green cloth","cloth"}));break;
case 2:set_name(BLU "��ɫ����" NOR, ({"blue cloth","cloth"}));break;
						}
					}
					else if (shen >= 10000)
					{
//						return HIC "�� ��  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(HIY "��Ƥ����" NOR, ({"yellow cloth","cloth"}));break;
case 1:set_name(CYN "�̴�װ" NOR, ({"brown cloth","cloth"}));break;
case 2:set_name(BLK "��ë����" NOR, ({"black cloth","cloth"}));break;
						}
					}
					else if (shen >= 1000)
					{
//						return HIC "�� ��  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(CYN "��ɫ����" NOR, ({"green cloth","cloth"}));break;
case 1:set_name(HIW "���ƺͷ�" NOR, ({"white cloth","cloth"}));break;
case 2:set_name(HIC "�ɺױ���" NOR, ({"blue cloth","cloth"}));break;
						}
					}
					else if (shen <= -1000000)
					{
//						return HIR "�� ħ  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "��Ѫ����" NOR, ({"red cloth","cloth"}));break;
case 1:set_name(GRN "��Ƥ��װ" NOR, ({"green cloth","cloth"}));break;
case 2:set_name(BLK "��ɫ���" NOR, ({"black cloth","cloth"}));break;
						}
					}
					else if (shen <= -100000)
					{
//						return HIR "�� ��  ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "Ѫɫս��" NOR, ({"red cloth","cloth"}));break;
case 1:set_name(HIW "���߽���" NOR, ({"snake cloth","cloth"}));break;
case 2:set_name(BLU "��ɫ����" NOR, ({"blue cloth","cloth"}));break;
						}
					}
					else if (shen <= -10000)
					{
//						return HIR "�� ħ  ͷ ��" NOR;
						switch (random(3))
						{
case 0:set_name(HIY "��Ƥս��" NOR, ({"fox cloth","cloth"}));break;
case 1:set_name(GRN "��ɫ��װ" NOR, ({"green cloth","cloth"}));break;
case 2:set_name(BLK "��ɫҹ����" NOR, ({"black cloth","cloth"}));break;
						}
					}
					else if (shen <= -1000)
					{
//						return HIR "�� ��  ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(HIY "��Ƥս��" NOR, ({"yellow cloth","cloth"}));break;
case 1:set_name(HIC "��ɫ����" NOR, ({"brown cloth","cloth"}));break;
case 2:set_name(BLK "��ɫƤ��" NOR, ({"black cloth","cloth"}));break;
						}
					}
					else
						switch(ob->query("class"))
						{
							case "bonze":
								if (budd >= 150)
								{
//									return HIY "�� ��  �� ��" NOR;
									switch (random(1))
									{
case 0:set_name(HIY "�������" NOR, ({"yellow cloth","cloth"}));break;
									}
								}
								else if (budd >= 120)
								{
//									return HIY "�� ʥ  ɮ ��" NOR;
									switch (random(1))
									{
case 0:set_name(HIY "�������" NOR, ({"yellow cloth","cloth"}));break;
									}
								}
								else if (budd >= 90)
								{
//									return HIY "�� ��  �� ��" NOR;
									switch (random(1))
									{
case 0:set_name(YEL "����ɫ����" NOR, ({"yellow cloth","cloth"}));break;
									}
								}
								else if (budd >= 60)
								{
//									return HIY "�� ��  �� ��" NOR;
									switch (random(1))
									{
case 0:set_name(YEL "��ɫ����" NOR, ({"yellow cloth","cloth"}));break;
									}
								}
								else if (budd >= 40)
								{
//									return HIY "�� ��  ʦ ��" NOR;
									switch (random(1))
									{
case 0:set_name(YEL "ǳ��ɫ����" NOR, ({"yellow cloth","cloth"}));break;
									}
								}
								else if (budd >= 30)
								{
//									return HIY "�� ��  �� ��" NOR;
									switch (random(1))
									{
case 0:set_name(YEL "�ư�ɮ��" NOR, ({"yellow cloth","cloth"}));break;
									}
								}
								else
								{
//									return "�� ɮ  �� ��";
									switch (random(1))
									{
case 0:set_name(YEL "��ɫɮ��" NOR, ({"white cloth","cloth"}));break;
									}
								}
								break;
							case "taoist":
//								return "�� ��  ʿ ��";
								switch (random(2))
								{
case 0:set_name(CYN "����ɫ����" NOR, ({"blue cloth","cloth"}));break;
case 1:set_name(HIW "���Ƶ���" NOR, ({"white cloth","cloth"}));break;
								}
								break;
							case "bandit":
//								return "�� ��  �� ��";
								switch (random(2))
								{
case 0:set_name(HIW "��ɫ����" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(HIB "��ɫƤ��" NOR, ({"black cloth","cloth"}));break;
								}
								break;
								case "shashou":
//								return "�� ɱ  �� ��";
								switch (random(2))
								{
case 0:set_name(BLU "��ɫս��" NOR, ({"blue cloth","cloth"}));break;
case 1:set_name(HIB "��ɫս��" NOR, ({"black cloth","cloth"}));break;
								}
								break;
							case "yishi":
//								return "�� ��  ʿ ��";
								switch (random(2))
								{
case 0:set_name(HIC "���װ" NOR, ({"blue cloth","cloth"}));break;
case 1:set_name(GRN "���ɳ���" NOR, ({"green cloth","cloth"}));break;
								}
								break;
							case "recruit":
//								return "�� ��  �� ��";
							case "scholar":
//								return "�� ��  �� ��";
							case "officer":
//								return "�� ��  �� ��";
							case "fighter":
//								return "�� ��  �� ��";
								switch (random(2))
								{
case 0:set_name(GRN "��ɫ����" NOR, ({"green cloth","cloth"}));break;
case 1:set_name(HIW "��ɫ����" NOR, ({"white cloth","cloth"}));break;
								}
								break;
							case "swordsman":
//								return "�� ��  ʿ ��";
							case "alchemist":
//								return "�� ��  ʿ ��";
							case "shaman":
//								return "�� ��  ҽ ��";
							case "beggar":
//								return "�� �л��� ��";
							default:
//								return "�� ƽ  �� ��";
								switch (random(2))
								{
case 0:set_name(WHT "��ɫ�̹�" NOR, ({"white cloth","cloth"}));break;
case 1:set_name(NOR "��ͨ����" NOR, ({"cloth"}));break;
								}
								break;
					}
			}
	}

	setup();
}
