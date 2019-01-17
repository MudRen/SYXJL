// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "˵������̫�����ˣ�����ô�ҵ���\n",
        "�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
//        string skill, teacher, master, skill_name;
        string skill, teacher, skill_name;
        object ob;
        int master_skill, my_skill, gin_cost,exp,times,i;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if(!arg || (sscanf(arg, "%s %s %d", teacher, skill,times)<2 ))
                  return notify_fail("ָ���ʽ��learnt|xuet <ĳ��> <����> [����]\n");
        if(times>30)
                  return notify_fail("��Ҳ̫̰�ˣ������30�Σ�\n");
        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("��Ҫ��˭��̣�\n");

        if( !living(ob) )
                return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

        if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) && me->query("marry/lover") != ob->query("id") ) {
//              if( (string)me->query("family/family_name") != (string)ob->query("family/family_name")
//              ||      (int)ob->query("family/privs") != -1 ) {
                return  notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
//                      if( !(ob->recognize_apprentice(me)) ) return 0;
//              }
        }

        if( !master_skill = ob->query_skill(skill, 1) )
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");

        notify_fail(ob->name() + "��Ը���������ܡ�\n");
        if( ob->prevent_learn(me, skill) )
                return 0;
        
        my_skill = me->query_skill(skill, 1);
        
        notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
        if( !SKILL_D(skill)->valid_learn(me) ) return 0;

        gin_cost = 150 / (int)me->query("int");

        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }   
     if(times<1)times=1;
     for(i=0;i<times;i++)
     {
        my_skill = me->query_skill(skill, 1);
        if(!me->is_apprentice_of(ob) && !ob->recognize_apprentice(me) )
            return notify_fail("����ȥ"+ob->query("name")+"��������㣡\n");
        else if(me->is_apprentice_of(ob) || ob->recognize_apprentice(me) )
            {
             if( my_skill >= master_skill )
                return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");
            }  
        else
           {
            if(my_skill >= master_skill-10*(me->query("marry/times")))
                return notify_fail("�������Ѿ������ٴ���İ�������ѧ������ˡ�\n"); 
           }
        
        if( (int)me->query("learned_points") >= (int)me->query("potential") )
                return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
        printf("����%s����йء�%s�������ʡ�\n", ob->name(),
                to_chinese(skill));

        if( ob->query("env/no_teach") )
                return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");

        tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",
                me->name(), to_chinese(skill)));

        if( (int)ob->query("jing") > gin_cost/5 + 1 ) {
                if( userp(ob) ) ob->receive_damage("jing", gin_cost/5 + 1);
        } else {
                write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲ�ᡣ\n");
                tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + "��\n");
                return 1;
        }
                

        if( (int)me->query("jing") > gin_cost ) {
                if( (string)SKILL_D(skill)->type()=="martial"
                &&      my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) { 
                        printf("Ҳ����ȱ��ʵս���飬���%s�Ļش������޷���ᡣ\n", ob->name() );
                        me->receive_damage("jing",gin_cost);
                        return 1;   
                } else {
                        if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
                                printf("������%s��ָ�����ԡ�%s����һ���ƺ���Щ�ĵá�\n", ob->name(),
                                        skill_name);
                        else
                                printf("������%s��ָ�����ƺ���Щ�ĵá�\n", ob->name());
                        me->add("learned_points", 1);
                        if (my_skill==0) my_skill=1;
                        exp=me->query("combat_exp");
                        if (exp==0) exp=1;
                        exp= random(me->query_int()*4*exp/my_skill/my_skill/my_skill);
                        if (exp < 10)  exp=random(me->query_int()+1);
                        me->improve_skill(skill,exp);
                }
        } else {
                gin_cost = me->query("jing");
                write("�����̫���ˣ����ʲôҲû��ѧ����\n");
                me->receive_damage("jing",gin_cost );
                return 1;   
        }

        me->receive_damage("jing", gin_cost );
      }
        return 1;
}

int help(object me)
{
        write(@HELP
    ָ���ʽ : learnt|xuet <ĳ��> <����> <����>
 
���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�

�������ָ�� : apprentice, practice, skills, study
HELP
        );
        return 1;
}

