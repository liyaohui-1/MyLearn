# 代理模式

使用代理类去操作真正的实现类，可以在真正的实现方法上加入限制条件。
例如：此例中，代理类实现了数据缓存，不需要实现类在每一次读取文件时，都重现读取一便文件，节约了资源和时间。