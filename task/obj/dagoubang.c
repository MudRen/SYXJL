#include <weapon.h>
#include <ansi.h>

 inherit STAFF;

void create()
{
         set_name(HIG"�򹷰�"NOR, ({ "dagou bang","bang", "staff"}) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500000);
     set("no_sell", 1);
      set("long", "һ�������͵����������ؤ����������\n");
     set("wield_msg", "$N��ﬡ���һ����һ�������������γ�һ��$n��\n");
     set("unwield_msg", "$N��$n������䣬���¶��һ˿Ц�⡣\n");
                set("material", "iron");
        }
         init_staff(300);
        setup();
}
