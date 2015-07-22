linkso(){
for s in `ls lib*.so.1\.*\.*`
do
echo $s >>list
done

sed -i 's/so.1.*/so/gp' list

for a in `cat list`
do
ln -sf $a.1.0.0 ./$a
ln -sf $a.1.0.0 ./$a.1
ln -sf $a.1.0.0 ./$a.1.0
done
rm list
}

ln -sf libdmnative.so.02.00.00 libdmnative.so.02.00
ln -sf libdmnative.so.02.00.00 libdmnative.so.02
ln -sf libdmnative.so.02.00.00 libdmnative.so
ln -sf libdmssession.so.02.00.00 libdmssession.so.02.00
ln -sf libdmssession.so.02.00.00 libdmssession.so.02
ln -sf libdmssession.so.02.00.00 libdmssession.so

linkso

ln -sf libipp-codecJP.so.1.0.0 libezxjpeg.so.1.0.0
cd inputmethods
linkso

cd ../dm_plugin
linkso

