// crate.c
inherit ITEM;
void create()
{
set_name("��ľ��", ({ "big crate", "crate"}));
set_weight(40000);
if( !clonep() ) {
set("unit", "��");
set("long", "����һ������װ����Ĵ�ľ�䣬�������൱���ء�\n");
set("value", 1);
set("wage", 5);
}
setup();
}
void init()
{
add_action("do_get", "get");

}
int do_get(string arg)
{
if( environment() != environment(this_player())
||!id(arg) ) return 0;
if( (int)this_player()->query("qi") < 10 ) {
write("������������ˣ���Ϣһ����˵�ɡ�\n");
return 1;
}
if( move(this_player()) ) {
message_vision("$N�����������ϵ�" + name() + "����������\n", this_player());
this_player()->consume_stat("jing", 10);
return 1;
}
}
