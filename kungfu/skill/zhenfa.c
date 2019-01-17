#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="array"; }

int valid_learn(object me)
{

        if( (int)me->query_skill("shenghuo-lingfa", 1) < 30 )
                return notify_fail("���ʥ�����Ϊ������û�а취����󷨵ĵı仯��\n");

        if( (int)me->query_skill("shenghuo-zhenfa", 1) >= (int)me->query_skill("array", 1) )
                return notify_fail("��Ļ�������Ϊ������û�а취���������ʥ���󷨡�\n");

        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
          || (string)weapon->query("id") != "shenghuo ling"
          && (string)weapon->query("id") != "tie ling")
               return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (string)me->query_skill_mapped("blade") != "shenghuo-lingfa" )
                return notify_fail("ʥ���󷨱������ʥ�������������\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("�������������ʥ���󷨡�\n");

        me->receive_damage("qi", 30);

        return 1;
}

int form_array(object leader, object *member)
{
        object weapon;
        int i;

        if( leader->query_temp("array") )
                return notify_fail("���Ѿ��������ˣ����Ҫ��ɢ���Σ�����team array dismiss��\n");

        if(sizeof(member) !=3)
                return notify_fail("ʥ������ֻ����������ɡ�\n");

        for(i=0;i< sizeof(member) ;i++ ) {
                if ( !stringp(member[i]->query_skill_mapped("array")) ||
                member[i]->query_skill_mapped("array") != "shenghuo-zhenfa" )
                        return notify_fail("�����л�����û�м��������󷨡�\n");

                if ( !stringp(member[i]->query_skill_mapped("blade")) ||
                member[i]->query_skill_mapped("blade") != "shenghuo-lingfa" )
                        return notify_fail("ʥ���󷨺�ʥ���������ϣ���Ķ��������˻�û�м���ʥ�����\n");

                if(member[i]->query_skill("shenghuo-zhenfa", 1) < 40
                || member[i]->query_skill("shenghuo-lingfa", 1) < 40)
                        return notify_fail(member[i]->name() + "���书�������������Ȱ����Ӷ����п�����\n");

                if (!objectp(weapon = member[i]->query_temp("weapon"))
                  || (string)weapon->query("id") != "shenghuo ling"
                  && (string)weapon->query("id") != "tie ling")
                        return notify_fail("�����л�����û��װ���������������޷�����ʥ�����󷨡�\n");

                if(!present(member[i]->query("id"), environment(leader)))
                        return notify_fail("�����л�����û�������ȱ𼱷����󷨡�\n");
        }

        message_vision( HIG "$N����������ֵķ�λվ�ã�׼���á�ʥ���󷨡�ӭ�У�\n" NOR, leader);
        for(i=0;i< sizeof(member) ;i++ ) {
                member[i]->set_temp("array", "shenghuo-zhenfa");
                member[i]->add_temp("apply/strength", (int)(leader->query_skill("shenghuo-zhenfa")/2) );
                member[i]->add_temp("apply/dexerity", (int)(leader->query_skill("shenghuo-zhenfa")/2) );
                member[i]->add_temp("apply/damage", (int)leader->query_skill("shenghuo-zhenfa"));
                member[i]->add_temp("apply/armor",(int)(leader->query_skill("shenghuo-zhenfa")*2));
        }

        remove_call_out("array_running");
        call_out("array_running", 2, leader, member);

        return 1;
}

void array_running(object leader, object *member)
{
        int i, j;
        object *enemy;

        for(i=0;i< sizeof(member) ;i++ ) {
                if( !member[i] || !member[i]->query_temp("array") ) {
                        message("team", HIW "�����顿����ֹͣ��ת��\n" NOR, member);
                        for(i = 0;i < sizeof(member);i++) {
                                if( !member[i] )        continue;
member[i]->delete_temp("array");
member[i]->add_temp("apply/strength", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/dexerity", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/damage", -(int)leader->query_skill("shenghuo-zhenfa"));
member[i]->add_temp("apply/armor",-(int)(leader->query_skill("shenghuo-zhenfa")*2));
                        }
                        return ;
                }
                if( environment(member[i]) != environment(leader) ) {
                        leader->add_temp("array_async_times", 1);
                        if(leader->query_temp("array_async_times") > (int)leader->query_skill("dagou-zhen", 1)/20 ) {
message("team", HIW "�����顿������" + leader->name() + "�쵼�޷������Զ���ɢ�ˡ�\n" NOR, member);
                                for(i = 0;i < sizeof(member);i++) {
member[i]->delete_temp("array");
member[i]->add_temp("apply/strength", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/dexerity", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/damage", -(int)leader->query_skill("shenghuo-zhenfa"));
member[i]->add_temp("apply/armor",-(int)(leader->query_skill("shenghuo-zhenfa")*2));
                                }
                                return ;
                        }
                        if( ((int)leader->query_temp("array_async_times") % 3 ) == 1 )
message("team", HIW "�����顿���󷨶��ο�ʼ��Щ���ˣ�����Ͽ���ס���Σ�\n" NOR, member);

                        remove_call_out("array_running");
                        call_out("array_running", 2, leader, member);
                        return ;
                }
        }
        enemy = leader->query_enemy();
        if( !sizeof(enemy) ) {
                for(i = 0;i < sizeof(member);i++) {
                        if( member[i] == leader )       continue;
                        if( sizeof(enemy = member[i]->query_enemy()) )  break;
                }
        }
        if( sizeof(enemy) ) {
                for(i = 0;i < sizeof(member);i++) {
                        member[i]->clean_up_enemy();
                        for(j = 0;j < sizeof(enemy);j++)
                                member[i]->fight_ob(enemy[j]);
                }
        }

        leader->set_temp("array_async_times", 0);
        remove_call_out("array_running");
        call_out("array_running", 2, leader, member);
}

int dismiss(object leader, object *member)
{
        int i;

        if( !leader->query_temp("array") )
                return notify_fail("��Ķ���Ŀǰ��û������κ����Ρ�\n");

        message("team", MAG "�����顿��" + leader->name() + "��ʥ���󷨽�ɢ�ˡ�\n" NOR, member);
        for(i=0;i< sizeof(member) ;i++ ) {
member[i]->delete_temp("array");
member[i]->add_temp("apply/strength", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/dexerity", -(int)(leader->query_skill("shenghuo-zhenfa")/2) );
member[i]->add_temp("apply/damage", -(int)leader->query_skill("shenghuo-zhenfa"));
member[i]->add_temp("apply/armor",-(int)(leader->query_skill("shenghuo-zhenfa")*2));
        }

        return 1;
}

// This function is called by COMBATD.C, to provide co-protect within array
int protect(object me, object who, int damage_bonus)
{
        return 0;
}