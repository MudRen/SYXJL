inherit ITEM;

void create()
{
        set_name( "����������", ({ "xiang shuxin", "shuxin" })
                 );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��������д�����š�\n");
              }
        setup();
      }
