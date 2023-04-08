#ifndef FINDPEAKS_H
#define FINDPEAKS_H

#include <vector>

using namespace std;

vector<int> findPeaks(vector<double> x, vector<double> plateauSize = {}, vector<double> height = {}, vector<double> threshold = {}, int distance = 0, vector<double> prominence = {}, int wlen = 2, vector<double> width = {}, double relHeight = 0.5) {
	
	vector<int> peaks;

	for (int i = 1; i < x.size() - 1; i++) {

		if (x[i - 1] < x[i]) {

			int iahead = i + 1;

			while (iahead < x.size() - 1 && x[iahead] == x[i]) {

				iahead++;
			}

			if (x[iahead] < x[i]) {

				bool peakflag = true;

				// Evaluate plateau size
				if (plateauSize.size() == 2) {

					int currentPlateauSize = iahead - i;

					if (currentPlateauSize < plateauSize[0] || currentPlateauSize > plateauSize[1]) {

						peakflag = false;
					}
				}

				// Evaluate height condition
				if (height.size() == 2) {

					int currentPeakIndex = (i + iahead - 1) / 2;

					if (x[currentPeakIndex] < height[0] || x[currentPeakIndex] > height[1]) {

						peakflag = false;
					}
				}

				// Evaluate threshold condition
				if (threshold.size() == 2) {

					int currentPeakIndex = (i + iahead - 1) / 2;

					if (min(x[currentPeakIndex] - x[currentPeakIndex - 1], x[currentPeakIndex] - x[currentPeakIndex + 1]) < threshold[0] || max(x[currentPeakIndex] - x[currentPeakIndex - 1], x[currentPeakIndex] - x[currentPeakIndex + 1]) > threshold[1]) {

						peakflag = false;
					}
				}

				if (peakflag) {
					
					peaks.push_back((i + iahead - 1) / 2);
				}

				i = iahead;
			}
		}
	}

	// Evaluate distance condition
	if (distance > 0) {

		vector<bool> eraseIndex(peaks.size(), false);
		vector<int> sortPeaks = peaks;
		sort(sortPeaks.begin(), sortPeaks.end(), [&x](int pos1, int pos2) {return (x[pos1] > x[pos2]); });	//sort peaks by the value of x[peaks]

		for (int i = 0; i < sortPeaks.size(); i++) {

			int j = find(peaks.begin(), peaks.end(), sortPeaks[i]) - peaks.begin();

			if (eraseIndex[j]) {

				continue;
			}

			int k = j - 1;

			while (k >= 0 && peaks[j] - peaks[k] < distance) {

				eraseIndex[k] = true;
				k--;
			}

			k = j + 1;

			while (k < peaks.size() && peaks[j] - peaks[k] < distance) {

				eraseIndex[k] = true;
				k++;
			}
		}

		int eraseCount = 0;

		for (int i = 0; i < eraseIndex.size(); i++) {

			if (eraseIndex[i]) {

				peaks.erase(peaks.begin() + i - eraseCount);
				eraseCount++;
			}
		}
	}

	// Evaluate prominence condition, wlen must be >= 2
	if (prominence.size() == 2 || width.size() == 2) {

		vector<int> copyPeaks = peaks;
		vector<double> prominences;
		vector<int> leftBases;
		vector<int> rightBases;
		int eraseCount = 0;

		for (int i = 0; i < copyPeaks.size(); i++) {

			int imin = 0;
			int imax = x.size() - 1;
			int peak = copyPeaks[i];
			double leftMin = x[peak];
			double rightMin = x[peak];
			int leftIndex = peak;
			int rightIndex = peak;
			int j;
			double currentProminence;

			if (wlen >= 2) {

				imin = max(peak - wlen / 2, imin);
				imax = min(peak + wlen / 2, imax);
			}

			j = peak;

			while (j >= imin && x[j] <= x[peak]) {

				if (x[j] < leftMin) {

					leftMin = x[j];
					leftIndex = j;
				}
				j--;
			}

			j = peak;

			while (j <= imax && x[j] <= x[peak]) {

				if (x[j] < rightMin) {

					rightMin = x[j];
					rightIndex = j;
				}
				j++;
			}

			currentProminence = x[peak] - max(leftMin, rightMin);

			if (prominence.size() == 2) {

				if (currentProminence >= prominence[0] && currentProminence <= prominence[1]) {

					prominences.push_back(currentProminence);
					leftBases.push_back(leftIndex);
					rightBases.push_back(rightIndex);
				}
				else {

					peaks.erase(peaks.begin() + i - eraseCount);
					eraseCount++;
				}
			}
			else {

				prominences.push_back(currentProminence);
				leftBases.push_back(leftIndex);
				rightBases.push_back(rightIndex);
			}
		}

		// Evaluate width condition
		if (width.size() == 2) {

			copyPeaks = peaks;
			eraseCount = 0;

			for (int i = 0; i < copyPeaks.size(); i++) {

				int peak = copyPeaks[i];
				int imin = leftBases[i];
				int imax = rightBases[i];
				double height = x[peak] - prominences[i] * relHeight;
				int j;
				double leftIp;
				double rightIp;
				double currentWidth;

				j = peak;

				while (j > imin && x[j] > height) {

					j--;
				}

				if (x[j] < height) {

					leftIp = j + (height - x[j]) / (x[j + 1] - x[j]);
				}

				j = peak;

				while (j < imax && x[j] > height) {

					j++;
				}

				if (x[j] < height) {

					rightIp = j - (height - x[j]) / (x[j - 1] - x[j]);
				}

				currentWidth = rightIp - leftIp;

				if (currentWidth < width[0] || currentWidth > width[1]) {

					peaks.erase(peaks.begin() + i - eraseCount);
					eraseCount++;
				}
			}
		}
	}

	return peaks;
}

#endif
