inherit ITEM;

void create()
{
        set_name("��̫������ͼ��", ({"bagua tu", "tu", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
     set("value", 0);
     set("no_sell", 1);
     set("no_put", 1);
     set("no_give", 1);
   set("long","һ�Ż���̫�����Ե����֡�\n"

   );
        set("material", "jade");
        set("skill", ([
                        "name": "taiji-shengong",
                        "exp_required": 40000,
                        "sen_cost": 40,
                        "difficulty": 40,
                        "max_skill": 100,
]) );
        }
}

