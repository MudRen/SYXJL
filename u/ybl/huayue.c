// huayue �������� by followme.2000.05

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
          set("no_get", HIR"�췴��!���������Ķ���!"NOR);
          set_name(BLINK HIW"��������"NOR,({ "huayue", "jian", "sword"}) );
          set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        
        else {
                set("unit", "��");
                set("wield_msg", HIY"$N����бָ���"+HIW"һ��������������"+HIY"ֻ��"+BLINK+HIW"��������"+NOR+HIY"����߷�����\n"NOR);
                set("long", "�˽���ͣ����������ȷ�����˼�֮�\n");
                  set("unwield_msg", HIW "$N�����дʣ�"+HIW"��������"+HIW"��Ȼ�䲻����Ӱ��\n" NOR);               
        }
          init_sword(5000);
        setup();
}


