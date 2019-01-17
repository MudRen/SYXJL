// rankd.c
// 1996-02-15 dts ranking related to "shen"
// modified by aeolus, adding more titles 11/29/2000

#include <ansi.h>

string query_rank(object ob)
{
      mapping fam;

      int shen;
      int budd;
      int exp;
      int age;
     if( ob->is_ghost() ) 
            return HIB "�� �»�Ұ�� ��" NOR;
      exp  = ob->query("combat_exp");
      shen = ob->query("shen");
      age = ob->query("age");
        //added by aeolus
        if ( (fam = ob->query("family")) && (fam["family_name"] == "������"
                || fam["family_name"] == "������"
                || fam["family_name"] == "������"
                || fam["family_name"] == "ѩɽ��"
                || fam["family_name"] == "��ɽ��"
                ))
                budd = ob->query_skill("buddhism",1);

      switch(ob->query("gender")) {
        case "Ů��":
              switch(wizhood(ob)) {
              case "(admin)": 
	       return HIW "��  Ů  ��  ��" NOR;
	         case "(sage)": 
	       return HIR "�� ������Ů ��" NOR;
              case "(arch)":   
           return HIY "��  ʥ  Ů  ��" NOR;
	          case "(angel)": 
	       return HIM "��  ��  ʹ  ��" NOR;
              case "(wizard)":        
           return HIG "��  ��  Ů  ��" NOR;
              case "(apprentice)":    
           return HIC "�� С �� Ů ��" NOR;
               default:
                        if( ((int)ob->query("PKS") > 50) )
                              return HIR "�� Ѫ    ū ��" NOR;
                        else if (shen >= 1000000)
                                 return HIW "�� ����Ů�� ��" NOR;
                        else if (shen >= 10000)
                                 return HIY "�� ����Ӣ�� ��" NOR;
                        else if (shen >= 1000)
                                 return HIC "�� �������� ��" NOR;      
                        else if (shen >= 100)
                                 return HIC "�� С������ ��" NOR;  
                        else if (shen >= 10)
                                 return HIC "�� �������� ��" NOR;
                        else if (shen >= 5)
                                 return "�� ���潭�� ��";
                        else if (shen <= -1000000)
                                 return HIR "�� ��ѪŮħ ��" NOR;                   
                        else if (shen <= -100000)
                                 return WHT "�� ��ѪħŮ ��" NOR;                  
                        else if (shen <= -10000)
                                 return BLU "�� ������ʹ ��" NOR;
                        else if (shen <= -1000)
                                 return HIC "�� ����ԹŮ ��" NOR;
                        else if (shen <= -100)
                                 return HIC "�� ������Ů ��" NOR;
                        else if (shen <= -10)
                                 return HIB "�� �����; ��" NOR;
                        else if( (int)ob->query("thief") > 15 ) 
                                 return HIW "�� Ů���� ��" NOR;
                        else
                        switch(ob->query("class")) {
                        case "bonze":
                             if (budd >= 150)
                                return HIY "�� ��  �� ��" NOR;
                             else if (budd >= 120)
                                return HIY "�� ʥ  �� ��" NOR;
                             else if (budd >= 90)
                                return HIY "�� ��  �� ��" NOR;
                             else if (budd >= 60)
                                return HIY "�� ��  �� ��" NOR;
                             else if (budd >= 30)
                                return HIY "�� ʦ  ̫ ��" NOR;
                             else if (age <= 16)
                                return "�� С��� ��";
                             else
                                return "�� ��  �� ��";
	          //added by aeolus
	          case "taoist":
                                        if (ob->query_skill("taoism",1)>100)
			return GRN"�� �������� ��"NOR;        
                                        else if (ob->query_skill("taoism",1)>150)
                                          return HIR"�� �������� ��"NOR;
                                        else if (ob->query_skill("taoism",1)>200)
                                          return HIW"�� ������ ��"NOR;
                                        else if (ob->query_skill("taoism",1)>250)
                                           return HIY"�� ��  Ů ��"NOR;
		             if (age <= 16)
                                          return "�� С �� �� ��";
        		             else if (age <= 30)
			return "�� ��  �� ��";
 		             else
			return "�� �ϵ��� ��";
                        case "yishi":   
                                return RED"�� Ů��ʿ ��"NOR;
                        case "taoist":  
                       
                        case "bandit":  
                                return HIB"�� Ů���� ��"NOR;
                        case "dancer":  
                                return RED"�� ��ɫ�輧 ��"NOR;          
                        case "officer": 
                                return RED"�� Ů���� ��"NOR;
                        case "fighter": 
                                return MAG"�� �糾Ů�� ��"NOR;                    
                        case "swordsman":       
                                return WHT"�� �轣��Ů ��"NOR;                    
                        case "alchemist":       
                                return HIC"�� Ů��ʿ ��"NOR;                   
                        case "shaman":  
                                return HIR"�� Ů��ҽ ��"NOR;
                        case "beggar":  
                                return BLU"�� Ů�л��� ��"NOR;      
                        case "shiny":
                                return HIY"�� ����Ůʹ ��"NOR;
	          //added by aeolus
	          case "scholar":
                                     if (ob->query_skill("literate",1)>100)
		            return HIG"�� ңң���� ��"NOR;         
                                     else if (ob->query_skill("literate",1)>150)
                                        return HIY"�� �Ż����� ��"NOR;
                                     else if (ob->query_skill("literate",1)>200)
                                        return HIW"�� Ůʥ�� ��"NOR;          
                                     else if (ob->query_skill("literate",1)>250&&ob->query("per",1)>25)
                                        return HIM"�� ��ò˫�� ��"NOR;   
                                     else if (age <= 16)
                                        return "�� Ůѧͯ ��";
                                     else if (age <= 30)
                                        return "�� ��  Ů ��";
                                     else
                                        return "�� Ůѧʿ ��";
                        case "prostitute":
                                return "�� ��  Ů ��";
                        default:
                                if (age <= 16)
                                    return "�� ������Ů ��";
                                else if(age<=30)
                                    return "�� ��  �� ��";
                                else if(age<=45)
                                    return "�� ��  �� ��";
                                else
                                    return "�� ������ ��";                  
                        }
                }
default:
                switch(wizhood(ob)) {
                case "(admin)": 
	              return HIW "��  ��  ��  ��" NOR;
	            case "(sage)": 
	              return HIR "�� �˲����� ��" NOR;
                case "(arch)":  
                  return HIY "��  ��  ��  ��" NOR;                
	            case "(angel)": 
	              return HIM "�� �� �� �� ��" NOR;
                case "(wizard)":        
                  return HIG "��  ��  ��  ��" NOR;        
                case "(apprentice)":    
                  return HIC "�� С �� �� ��" NOR;      
                default:
                        if( ((int)ob->query("PKS") > 60) )
                                 return HIR "�� ɱ��ħ�� ��" NOR;
                        else if (shen >= 1000000)
                                 return HIW "�� ����̩�� ��" NOR;
                        else if (shen >= 100000)
                                 return HIY "�� �������� ��" NOR;
                        else if (shen >= 10000)
                                 return HIY "�� ����һʱ ��" NOR;
                        else if (shen >= 1000)
                                 return HIC "�� �������� ��" NOR;      
                        else if (shen >= 100)
                                 return HIC "�� С������ ��" NOR;  
                        else if (shen >= 10)
                                 return HIC "�� �������� ��" NOR;
                        else if (shen >= 5)
                                 return "�� ���뽭�� ��";
                        else if (shen <= -1000000)
                                 return HIR "�� ����ħͷ ��" NOR;                   
                        else if (shen <= -100000)
                                 return RED "�� �������� ��" NOR;                  
                        else if (shen <= -10000)
                                 return HIG "�� ���һ�� ��" NOR;
                        else if (shen <= -1000)
                                 return HIG "�� ����Զ�� ��" NOR;
                        else if (shen <= -100)
                                 return HIC "�� С�ж��� ��" NOR;
                        else if (shen <= -10)
                                 return HIB "�� �����; ��" NOR;
                        else if( (int)ob->query("thief") > 15 ) 
                                 return HIW "�� �������� ��" NOR;                              
                        else
                        switch(ob->query("class")) {
		    //modified by aeolus
                                case "bonze":
                                        if (budd >= 150)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (budd >= 120)
                                                return HIY "�� ʥ  ɮ ��" NOR;
                                        else if (budd >= 90)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (budd >= 60)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (budd >= 40)
                                                return HIY "�� ��  ʦ ��" NOR;
                                        else if (budd >= 30)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (age <= 16)
                                                return "�� С���� ��";
                                        else
                                                return "�� ɮ  �� ��";
	          //added by aeolus
	          case "taoist":
                                        if (ob->query_skill("taoism",1)>100)
			return GRN"�� �������� ��"NOR;        
                                        else if (ob->query_skill("taoism",1)>150)
                                          return HIR"�� �������� ��"NOR;
                                        else if (ob->query_skill("taoism",1)>200)
                                          return HIW"�� ������ ��"NOR;
                                        else if (ob->query_skill("taoism",1)>250)
                                           return HIY"�� ��  �� ��"NOR;
                                        else if (age <= 16)
                                          return "�� С �� ʿ ��";
                                        else if (age <= 30)
                                           return "�� ��  ʿ ��";
                                        else
                                           return "�� ��  �� ��";
	          //added by aeolus
	          case "scholar":
                                     if (ob->query_skill("literate",1)>100)
                                        return HIG"�� ������� ��"NOR;        
                                     else if (ob->query_skill("literate",1)>150)
                                        return HIY"�� �Ÿ߰˶� ��"NOR;
                                     else if (ob->query_skill("literate",1)>200)
                                        return HIM"�� ѧ���峵 ��"NOR;
                                     else if (ob->query_skill("literate",1)>250)
                                        return HIW"�� ʥ  �� ��"NOR;             
                                     else if (age <= 16)
                                        return "�� ѧ  ͯ ��";
                                     else if (age <= 45)
                                        return "�� ��  �� ��";
                                     else
                                        return "�� ����� ��";
                        case "yishi":   
                                return RED"�� ������ʿ ��"NOR;                           
                        case "bandit":  
                                return HIB"�� ���Ͼ��� ��"NOR;
                        case "officer": 
                                return HIG"�� ��  �� ��"NOR;
                        case "swordsman":       
                                return WHT"�� ���齣�� ��"NOR;                    
                        case "alchemist":       
                                return HIC"�� ��  ʿ ��"NOR;                   
                        case "shaman":  
                                return HIR"�� ��  ҽ ��"NOR;
                        case "beggar":  
                                return MAG"�� ��л��� ��"NOR;      
                        case "shiny":
                                return HIY"�� ����ʹ�� ��"NOR;
		//added by aeolus
                                case "eunach":
                                        budd = ob->query_skill("pixie-jian",1);
                                        if (budd >= 110)
                                                return HIM "�����ڸ��֡�" NOR;
                                        else if (budd >= 100)
                                                return HIM "�������򻧡�" NOR;
                                        else if (budd >= 90)
                                                return HIM "������ǧ����" NOR;
                                        else if (budd >= 80)
                                                return HIM "�������ٻ���" NOR;
                                        else if (budd >= 70)
                                                return HIM "������ʮ����" NOR;
                                        else if (budd >= 60)
                                                return HIM "������������" NOR;
                                        else return "�� ��  �� ��";
                                case "prostitute":
                                        return "�� ��  �� ��";
                        default:
                                if (age <= 16)
                                  return "�� �������� ��";
                                else if(age<=30)
                                    return "�� ׳  ��  ��";
                                else if(age<=45)
                                    return "�� ��  �� ��";
                                else
                                    return "�� ��ү�� ��";           
                }
          }
    }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ̫";
                                else return "ʦ̫";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С�ɹ�";
                                else return "�ɹ�";
                                break;
                        default:
                                if( age < 18 ) return "С����";
                                else if( age < 30 ) return "����";
                                else if( age < 40 ) return "����";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ��";
                                else return "��ʦ";
                                break;
                        case "taoist":
if( age < 18 ) return "����";
                                else return "����";
                                break;
                        case "scholar":
                                if( age < 18 ) return "С�๫";
                                else if( age < 50 ) return "�๫";
                                else return "������";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "С�ϵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ǰ��";
                                break;
                        default:
                                if( age < 20 ) return "С�ֵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ү��";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
         
               case "bonze":
                                if( age < 18 ) return "С����";
                                if( age < 30 ) return "����";
                                else return "������";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С��Ů";
                                if( age < 30 ) return "��Ů";
                                else return "������";
                        default:
                                if( age < 18 ) return "С��Ƥ";
                                if( age < 25 ) return "С����";
                                if( age < 40 ) return "������";
                                else return "����̫��";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "С��ͺ";
                                if( age < 50 ) return "��ͺ¿";
                                else return "��ͺ¿";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С��ë";
                                if( age < 30 ) return "��ţ����";
                                else return "����ë";
                                break;
                        case "scholar":
                                if( age < 18 ) return "С�����";
                                else if( age < 50 ) return "�������";
                                else return "��ͯ��";
                                break;
                        default:
                                if( age < 20 ) return "С���˵�";
                                if( age < 30 ) return "����";
                                if( age < 50 ) return "����";
                                if( age < 80 ) return "��ƥ��";
                                else return "�ϲ���";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        case "taoist":
                                return "ƶ��";
                                break;
                        default:
                                if( age < 20 ) return "СŮ��";
                                if( age > 50 ) return "����";
                                else return "���";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "С����";
                                if( age < 40 ) return "ƶɮ";
                                else return "����";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С��";
                                if( age < 30 ) return "ƶ��";
                                else return "�ϵ�";
                                break;
                        case "scholar":
                                if( age < 30 ) return "����";
                                else return "����";
                                break;
                        default:
                                if( age < 50 ) return "����";
                                else return "��ͷ��";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;
        
        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return 
"ƶ��";
                                else return "����";
                                break;
                        case "taoist":
                                return "���ɹ�";
                                break;
                        default:
                                if( age < 20 ) return "������";
                                if( age < 30 ) return "��������";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "�����";
                                else return "�Ϻ���";
                                break;
                                if( age < 30 ) return "��ɽ��";
                                return "�ϵ���";
                                break;
                        case "scholar":
                                if( age < 50 ) return "���๫";
                                else return "�Ϸ�����";
                                break;
                        default:
                                if( age < 20 ) return "����ү��";
                                if( age < 40 ) return "��ү��";
                                else return "����";
                                break;
                        }
        }
}
string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age")) {
                        a1 = this_player()->query("mud_age");
                } else
	  {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "�ֵ���";
                else
                        return "С����";
        }
}
