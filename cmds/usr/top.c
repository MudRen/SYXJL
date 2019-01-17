#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
        object *list,*ob;
        int i;
        string msg;
      ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
        list = sort_array(ob, (: top_list :));
      msg =  "\n            �� "+BCYN HIW+MUD_NAME+"���߸������а�"NOR" ��\n"+HIW;
      msg += "���������ө��ߩ����������������ө����ߩ��ө���������\n";
        msg += "�� ���� ��    ��        ��    �� ��  �� �� ��  �� ��\n";
        msg += "�ĩ������ة��������������������ة��������ة���������\n";
        for (i = 0 ;i < 10 ; i++) {
        if( i >= sizeof(list)) msg += "����ʱ��ȱ�� \n";
                else {
                if(list[i] == me) 
              {
                msg +=HIY;
              }
              else
              { 
                msg +=HIW;
              }
  msg += sprintf("��  %-5s %-22s%-10s %5d  ��\n"NOR,chinese_number(i+1),list[i]->query("name")+"("+
        capitalize(list[i]->query("id"))+")", list[i]->query("family")?  list[i]->query("family/family_name"):"��ͨ����",
        get_score(list[i]));
                }
                         }
        msg += HIW+"����������������������������������������������������\n";
        msg += "  " + NATURE_D->game_time() + "�ǡ�\n"+NOR;
        write(msg);
        return 1;

}
int top_list(object ob1, object ob2)
{
      int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);

      return score2 - score1;
}
int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;

      reset_eval_cost();
        skills = ob->query_skills();
        if (!sizeof(skills)) return 1; 
        ski  = keys(skills);
        for(i = 0; i<sizeof(ski); i++) {
                        tlvl += skills[ski[i]];
                        }  
        score = tlvl/10;
        score += ob->query("max_neili")/10;
        score += ob->query_str() + ob->query_int() + ob->query_dex() + ob->query_con();
        score += (int)ob->query("combat_exp")/2500;
        return score;
}
int help(object me)
{
write(@HELP
ָ���ʽ : top 
���ָ���������֪������ʮ���������Щ����ȥ�����ǡ� 
HELP
    );
    return 1;
}
