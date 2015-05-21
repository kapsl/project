#!/bin/bash
#
mkdir resultsMobile
cd ./MobileSingleSourceDest
for i in AODVNetwork-*
do mv $i SingleSDPair$i
done
for i in General-*
do mv $i SingleSDPair$i
done
mv -v * ../resultsMobile
cd ..
#
cd ./MobileTenSourceDest
for i in AODVNetwork-*
do mv $i TenSDPair$i
done
for i in General-*
do mv $i TenSDPair$i
done
mv -v * ../resultsMobile
cd ..
#
cd ./MobileFifteenSourceDest
for i in AODVNetwork-*
do mv $i FifteenSDPair$i
done
for i in General-*
do mv $i FifteenSDPair$i
done
mv -v * ../resultsMobile
cd ..
#
cd ./MobileTwentySourceDest
for i in AODVNetwork-*
do mv $i TwentySDPair$i
done
for i in General-*
do mv $i TwentySDPair$i
done
mv -v * ../resultsMobile
cd ..
#
cd ./MobileThirtySourceDest
for i in AODVNetwork-*
do mv $i ThirtySDPair$i
done
#
for i in General-*
do mv $i ThirtySDPair$i
done
mv -v * ../resultsMobile
cd ..
##
#
#
mkdir resultsStatic
cd ./StaticSingleSourceDest
for i in AODVNetwork-*
do mv $i SingleSDPair$i
done
for i in General-*
do mv $i SingleSDPair$i
done
mv -v * ../resultsStatic
cd ..
#
cd ./StaticTenSourceDest
for i in AODVNetwork-*
do mv $i TenSDPair$i
done
for i in General-*
do mv $i TenSDPair$i
done
mv -v * ../resultsStatic
cd ..
#
cd ./StaticFifteenSourceDest
for i in AODVNetwork-*
do mv $i FifteenSDPair$i
done
for i in General-*
do mv $i FifteenSDPair$i
done
mv -v * ../resultsStatic
cd ..
#
cd ./StaticTwentySourceDest
for i in AODVNetwork-*
do mv $i TwentySDPair$i
done
for i in General-*
do mv $i TwentySDPair$i
done
mv -v * ../resultsStatic
cd ..
#
cd ./StaticThirtySourceDest
for i in AODVNetwork-*
do mv $i ThirtySDPair$i
done
#
for i in General-*
do mv $i ThirtySDPair$i
done
mv -v * ../resultsStatic
cd ..
