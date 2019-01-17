// shoe.c
// writed by shadow
// This is the basic equip for players just login.

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	object ob;
	mapping fam;
	int shen;
	int budd;

	set_name("��Ь", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
        	set_default_object(__FILE__);
	else {
	        set("unit", "˫");
	        set("material", "shoe");
	        set("armor_prop/armor", 1);
	}

	ob=this_player();

	if ( ob->query("gender") == "Ů��" )
	{
		set("female_only", 1);
	}

//	if( ob->is_ghost() )
//	{
//		return HIB "�� ��  �� ��" NOR;
//		switch (random(2))
//		{
//			case 0:set_name(BLK "��ɫɥ��" NOR, ({"black shoe","shoe"}));break;
//			case 1:set_name(HIW "��ɫɥ��" NOR, ({"white shoe","shoe"}));break;
//		}
//	}

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
case 0:set_name(HIW "������ѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(HIR "�����ѥ" NOR, ({"pink shoe","shoe"}));break;
					}
					break;
				case "(sage)":
//					return HIW "�� Ů  �� ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "ǳ����ѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(WHT "������ѥ" NOR, ({"pink shoe","shoe"}));break;
					}
					break;
					
				case "(arch)":
//					return HIY "�� ����Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "������ѥ" NOR, ({"purple shoe","shoe"}));break;
case 1:set_name(HIM "�����ѥ" NOR, ({"pink shoe","shoe"}));break;
					}
					break;
				case "(angel)":
//					return HIG "�� ��  Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(HIY "�����ѥ" NOR, ({"black shoe","shoe"}));break;
case 1:set_name(HIG "������ѥ" NOR, ({"green shoe","shoe"}));break;
					}
					break;
					
				case "(wizard)":
//					return HIG "�� ��  Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(HIY "���ѥ" NOR, ({"black shoe","shoe"}));break;
case 1:set_name(HIG "����ѥ" NOR, ({"green shoe","shoe"}));break;
					}
					break;
				case "(apprentice)":
//					return HIC "�� С��Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "��ɫСѥ" NOR, ({"purple shoe","shoe"}));break;
case 1:set_name(HIM "���Сѥ" NOR, ({"pink shoe","shoe"}));break;
					}
					break;
				case "(genie)":
//					return HIC "�� С��Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "��ɫСѥ" NOR, ({"purple shoe","shoe"}));break;
case 1:set_name(HIM "���Сѥ" NOR, ({"pink shoe","shoe"}));break;
					}
					break;
					
				case "(immortal)":
//					return HIC "�� ��  Ů ��" NOR;
					switch (random(2))
					{
case 0:set_name(MAG "����ѥ" NOR, ({"purple shoe","shoe"}));break;
case 1:set_name(HIM "���ѥ" NOR, ({"pink shoe","shoe"}));break;
					}
					break;
				default:
					if ( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					{
//						return HIR "��Ůɱ��ħ��" NOR;
						switch (random(1))
						{
case 0:set_name(RED "Ѫսѥ" NOR, ({"read shoe","shoe"}));break;
						}
					}
					if( (int)ob->query("thief") > 10 )
					{
//						return HIW "��Ů �� �ԡ�" NOR;
						switch (random(1))
						{
case 0:set_name(HIB "��ɫƤѥ" NOR, ({"black shoe","shoe"}));break;
						}
					}
					if (shen >= 1000000)
					{
//						return HIC "������Ů����" NOR;
						switch (random(3))
						{
case 0:set_name(RED "���սѥ" NOR, ({"red shoe","shoe"}));break;
case 1:set_name(HIY "��ɫ��ѥ" NOR, ({"yellow shoe","shoe"}));break;
case 2:set_name(BLK "��ɫսѥ" NOR, ({"black shoe","shoe"}));break;
						}
					}
					else if (shen >= 100000)
					{
//						return HIC "�� Ů���� ��" NOR;
						switch (random(3))
						{
case 0:set_name(YEL "ǳ��Сѥ" NOR, ({"yellow shoe","shoe"}));break;
case 1:set_name(MAG "��ɴСѥ" NOR, ({"purple shoe","shoe"}));break;
case 2:set_name(HIG "��ɫСѥ" NOR, ({"green shoe","shoe"}));break;
						}
					}
					else if (shen >= 10000)
					{
//						return HIC "�� Ů  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(HIW "��ɫСѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(MAG "ǳ��Сѥ" NOR, ({"purple shoe","shoe"}));break;
case 2:set_name(BLK "��ɫСѥ" NOR, ({"black shoe","shoe"}));break;
						}
					}
					else if (shen >= 1000)
					{
//						return HIC "�� Ů���� ��" NOR;
						switch (random(3))
						{
case 0:set_name(CYN "��ɫСѥ" NOR, ({"green shoe","shoe"}));break;
case 1:set_name(MAG "ǳ��Сѥ" NOR, ({"purple shoe","shoe"}));break;
case 2:set_name(GRN "����С��ѥ" NOR, ({"green shoe","shoe"}));break;
						}
					}
					else if (shen <= -1000000)
					{
//						return HIR "�� Ůħ�� ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "���սѥ" NOR, ({"red shoe","shoe"}));break;
case 1:set_name(MAG "����ѥ" NOR, ({"purple shoe","shoe"}));break;
case 2:set_name(BLK "��ɫҹ��ѥ" NOR, ({"black shoe","shoe"}));break;
						}
					}
					else if (shen <= -100000)
					{
//						return HIR "�� Ů��ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(WHT "��ɫսѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(CYN "��ɫ��ѥ" NOR, ({"green shoe","shoe"}));break;
case 2:set_name(BLK "��ɫ����ѥ" NOR, ({"black shoe","shoe"}));break;
						}
					}
					else if (shen <= -10000)
					{
//						return HIR "�� Ů  ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "����ѥ" NOR, ({"red shoe","shoe"}));break;
case 1:set_name(MAG "ǳ����ѥ" NOR, ({"purple shoe","shoe"}));break;
case 2:set_name(HIC "��ɫ��ѥ" NOR, ({"green shoe","shoe"}));break;
						}
					}
					else if (shen <= -1000)
					{
//						return HIR "�� Ů��ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "�����ѥ" NOR, ({"red shoe","shoe"}));break;
case 1:set_name(MAG "ǳ����ѥ" NOR, ({"purple shoe","shoe"}));break;
case 2:set_name(GRN "��ɫ��ѥ" NOR, ({"green shoe","shoe"}));break;
						}
					}
					else
						switch(ob->query("class"))
						{
							case "bonze":
//								return "�� ��  �� ��";
								switch (random(2))
								{
case 0:set_name(NOR "��ɫɮѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(YEL "����ɫɮѥ" NOR, ({"yellow shoe","shoe"}));break;
								}
								break;
							case "taoist":
//								return "�� Ů  �� ��";
								switch (random(2))
								{
case 0:set_name(NOR "��ɫ��ѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(YEL "����ɫ��ѥ" NOR, ({"yellow shoe","shoe"}));break;
								}
								break;
							case "shashou":
//								return HIY "��Ů ɱ �֡�" NOR;
								switch (random(2))
								{
case 0:set_name(GRN "��ɫ��ѥ" NOR, ({"green shoe","shoe"}));break;
case 1:set_name(HIC "��ɫ��ѥ" NOR, ({"green shoe","shoe"}));break;
								}
								break;
							case "yishi":
//								return "��Ů �� ʿ��";
								switch (random(2))
								{
case 0:set_name(MAG "ǳ����Ь" NOR, ({"purple shoe","shoe"}));break;
case 1:set_name(YEL "��ɫ��Ь" NOR, ({"yellow shoe","shoe"}));break;
								}
								break;
							case "recruit":
//								return "�� ��  Ů ��";
								switch (random(2))
								{
case 0:set_name(WHT "��ɫ����ѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(CYN "��ɫ��Ь" NOR, ({"yellow shoe","shoe"}));break;
								}
								break;
							case "bandit":
//								return "�� Ů���� ��";
								switch (random(2))
								{
case 0:set_name(BLK "��ɫҹ��ѥ" NOR, ({"black shoe","shoe"}));break;
case 1:set_name(BLU "������Ь" NOR, ({"blue shoe","shoe"}));break;
								}
								break;
							case "dancer":
//								return "�� ��  �� ��";
								switch (random(5))
								{
case 0:set_name(RED "Ʈ����Ь" NOR, ({"red shoe","shoe"}));break;
case 1:set_name(MAG "��ɫ��Ь" NOR, ({"purple shoe","shoe"}));break;
case 2:set_name(GRN "��ɫ��Ь" NOR, ({"green shoe","shoe"}));break;
case 3:set_name(HIM "�ۺ�ɫ��Ь" NOR, ({"pink shoe","shoe"}));break;
case 4:set_name(HIY "���ɫ��Ь" NOR, ({"yellow shoe","shoe"}));break;
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
case 0:set_name(MAG "����Ь" NOR, ({"purple shoe","shoe"}));break;
case 1:set_name(YEL "����Ь" NOR, ({"yellow shoe","shoe"}));break;
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
case 0:set_name(NOR "�ײ�Ь" NOR, ({"shoe"}));break;
case 1:set_name(NOR "�ֲ�Ь" NOR, ({"shoe"}));break;
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
case 0:set_name(WHT "������ѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(YEL "�����ѥ" NOR, ({"gold shoe","shoe"}));break;
					}
					break;
				case "(sage)":			
//					return HIW "�� ��  �� ��" NOR;
					switch (random(2))
					{
case 0:set_name(WHT "����ѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(YEL "����ѥ" NOR, ({"gold shoe","shoe"}));break;
					}
					break;
					
				case "(arch)":
//					return HIY "�� ����ʦ ��" NOR;
					switch (random(2))
					{
case 0:set_name(HIW "������ѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(HIC "��ɫ��ѥ" NOR, ({"green shoe","shoe"}));break;
					}
					break;
				case "(angel)":
//					return HIG "�� ��  ʦ ��" NOR;
					switch (random(2))
					{
case 0:set_name(BLU "����ѥ" NOR, ({"blue shoe","shoe"}));break;
case 1:set_name(HIY "����ѥ" NOR, ({"yellow shoe","shoe"}));break;
					}
					break;

				case "(wizard)":
//					return HIG "�� ��  ʦ ��" NOR;
					switch (random(2))
					{
case 0:set_name(BLU "��ɫ��ѥ" NOR, ({"blue shoe","shoe"}));break;
case 1:set_name(HIY "��ɫ��ѥ" NOR, ({"yellow shoe","shoe"}));break;
					}
					break;
				case "(apprentice)":
//					return HIC "����ʦѧͽ��" NOR;
					switch (random(2))
					{
case 0:set_name(BLK "�ڲ���ѥ" NOR, ({"black shoe","shoe"}));break;
case 1:set_name(HIC "��ɫ��ѥ" NOR, ({"blue shoe","shoe"}));break;
					}
					break;
				case "(genie)":
//					return HIC "����ʦѧͽ��" NOR;
					switch (random(2))
					{
case 0:set_name(BLK "�ڲ���ѥ" NOR, ({"black shoe","shoe"}));break;
case 1:set_name(HIC "��ɫ��ѥ" NOR, ({"blue shoe","shoe"}));break;
					}
					break;

				case "(immortal)":
//					return HIC "�� ��  �� ��" NOR;
					switch (random(2))
					{
case 0:set_name(HIC "����ɫ��ѥ" NOR, ({"purple shoe","shoe"}));break;
case 1:set_name(HIB "����ɫ��ѥ" NOR, ({"blue shoe","shoe"}));break;
					}
					break;
				default:
					if ( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					{
//						return HIR "�� ɱ��ħ ��" NOR;
						switch (random(1))
						{
case 0:set_name(HIR "��쳤ѥ" NOR, ({"read shoe","shoe"}));break;
						}
					}
					if( (int)ob->query("thief") > 10 )
					{
//						return HIW "�� ��  �� ��" NOR;
						switch (random(1))
						{
case 0:set_name(WHT "��Ƥѥ" NOR, ({"white shoe","shoe"}));break;
						}
					}
					if (shen >= 1000000)
					{
//						return HIC "������������" NOR;
						switch (random(3))
						{
case 0:set_name(YEL "��˿ѥ" NOR, ({"gold shoe","shoe"}));break;
case 1:set_name(CYN "�̴�ѥ" NOR, ({"brown shoe","shoe"}));break;
case 2:set_name(WHT "ѩ����ѥ" NOR, ({"white shoe","shoe"}));break;
						}
					}
					else if (shen >= 100000)
					{
//						return HIC "�� ��  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "Ѫɫսѥ" NOR, ({"red shoe","shoe"}));break;
case 1:set_name(HIG "��ɫѥ" NOR, ({"green shoe","shoe"}));break;
case 2:set_name(BLU "��ɫѥ" NOR, ({"blue shoe","shoe"}));break;
						}
					}
					else if (shen >= 10000)
					{
//						return HIC "�� ��  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(HIY "��Ƥѥ" NOR, ({"yellow shoe","shoe"}));break;
case 1:set_name(CYN "�̴�ѥ" NOR, ({"brown shoe","shoe"}));break;
case 2:set_name(BLK "��ë��ѥ" NOR, ({"black shoe","shoe"}));break;
						}
					}
					else if (shen >= 1000)
					{
//						return HIC "�� ��  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(CYN "��ɫ��ѥ" NOR, ({"green shoe","shoe"}));break;
case 1:set_name(HIW "����ѥ" NOR, ({"white shoe","shoe"}));break;
case 2:set_name(HIC "�ɺ�ѥ" NOR, ({"blue shoe","shoe"}));break;
						}
					}
					else if (shen <= -1000000)
					{
//						return HIR "�� ħ  �� ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "Ѫ��սѥ" NOR, ({"red shoe","shoe"}));break;
case 1:set_name(GRN "��Ƥѥ" NOR, ({"green shoe","shoe"}));break;
case 2:set_name(BLK "��ɫ��ѥ" NOR, ({"black shoe","shoe"}));break;
						}
					}
					else if (shen <= -100000)
					{
//						return HIR "�� ��  ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(RED "Ѫɫսѥ" NOR, ({"red shoe","shoe"}));break;
case 1:set_name(HIW "����ѥ" NOR, ({"snake shoe","shoe"}));break;
case 2:set_name(BLU "��ɫ��ѥ" NOR, ({"blue shoe","shoe"}));break;
						}
					}
					else if (shen <= -10000)
					{
//						return HIR "�� ħ  ͷ ��" NOR;
						switch (random(3))
						{
case 0:set_name(HIY "��Ƥѥ" NOR, ({"fox shoe","shoe"}));break;
case 1:set_name(GRN "����ѥ" NOR, ({"green shoe","shoe"}));break;
case 2:set_name(BLK "��ɫҹ��ѥ" NOR, ({"black shoe","shoe"}));break;
						}
					}
					else if (shen <= -1000)
					{
//						return HIR "�� ��  ħ ��" NOR;
						switch (random(3))
						{
case 0:set_name(HIY "��Ƥѥ" NOR, ({"yellow shoe","shoe"}));break;
case 1:set_name(HIC "��ɫ��Ͱѥ" NOR, ({"brown shoe","shoe"}));break;
case 2:set_name(BLK "��ɫƤѥ" NOR, ({"black shoe","shoe"}));break;
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
case 0:set_name(HIW "��ɫɮѥ" NOR, ({"yellow shoe","shoe"}));break;
									}
								}
								else if (budd >= 120)
								{
//									return HIY "�� ʥ  ɮ ��" NOR;
									switch (random(1))
									{
case 0:set_name(HIW "��ɫɮѥ" NOR, ({"yellow shoe","shoe"}));break;
									}
								}
								else if (budd >= 90)
								{
//									return HIY "�� ��  �� ��" NOR;
									switch (random(1))
									{
case 0:set_name(WHT "��ɮѥ" NOR, ({"yellow shoe","shoe"}));break;
									}
								}
								else if (budd >= 60)
								{
//									return HIY "�� ��  �� ��" NOR;
									switch (random(1))
									{
case 0:set_name(WHT "��ɮѥ" NOR, ({"yellow shoe","shoe"}));break;
									}
								}
								else if (budd >= 40)
								{
//									return HIY "�� ��  ʦ ��" NOR;
									switch (random(1))
									{
case 0:set_name(WHT "��ɮѥ" NOR, ({"yellow shoe","shoe"}));break;
									}
								}
								else if (budd >= 30)
								{
//									return HIY "�� ��  �� ��" NOR;
									switch (random(1))
									{
case 0:set_name(WHT "��ɮѥ" NOR, ({"yellow shoe","shoe"}));break;
									}
								}
								else
								{
//									return "�� ɮ  �� ��";
									switch (random(1))
									{
case 0:set_name(WHT "��ɮѥ" NOR, ({"white shoe","shoe"}));break;
									}
								}
								break;
							case "taoist":
//								return "�� ��  ʿ ��";
								switch (random(2))
								{
case 0:set_name(HIB "��ɫ��ѥ" NOR, ({"blue shoe","shoe"}));break;
case 1:set_name(HIW "�ײ�ѥ" NOR, ({"white shoe","shoe"}));break;
								}
								break;
							case "bandit":
//								return "�� ��  �� ��";
								switch (random(2))
								{
case 0:set_name(HIW "����ѥ" NOR, ({"white shoe","shoe"}));break;
case 1:set_name(HIC "��ɫƤѥ" NOR, ({"black shoe","shoe"}));break;
								}
								break;
								case "shashou":
//								return "�� ɱ  �� ��";
								switch (random(2))
								{
case 0:set_name(BLU "��ɫ��ѥ" NOR, ({"blue shoe","shoe"}));break;
case 1:set_name(HIB "��ɫƤѥ" NOR, ({"black shoe","shoe"}));break;
								}
								break;
							case "yishi":
//								return "�� ��  ʿ ��";
								switch (random(2))
								{
case 0:set_name(GRN "��ѥ" NOR, ({"green shoe","shoe"}));break;
case 1:set_name(HIB "���ѥ" NOR, ({"black shoe","shoe"}));break;
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
case 0:set_name(GRN "��ѥ" NOR, ({"green shoe","shoe"}));break;
case 1:set_name(HIB "���ѥ" NOR, ({"black shoe","shoe"}));break;
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
case 0:set_name(GRN "��Ь" NOR, ({"green shoe","shoe"}));break;
case 1:set_name(NOR "��Ь" NOR, ({"shoe"}));break;
								}
								break;
					}
			}
	}

	setup();
}
