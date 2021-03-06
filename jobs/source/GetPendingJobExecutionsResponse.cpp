/* Copyright 2010-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.

* This file is generated
*/
#include <aws/iotjobs/GetPendingJobExecutionsResponse.h>

namespace Aws
{
    namespace Iotjobs
    {

        void GetPendingJobExecutionsResponse::LoadFromObject(
            GetPendingJobExecutionsResponse &val,
            const Aws::Crt::JsonView &doc)
        {
            (void)val;
            (void)doc;

            if (doc.ValueExists("clientToken"))
            {
                val.ClientToken = doc.GetString("clientToken");
            }

            if (doc.ValueExists("queuedJobs"))
            {
                auto queuedJobsList = doc.GetArray("queuedJobs");
                val.QueuedJobs = Aws::Crt::Vector<Aws::Iotjobs::JobExecutionSummary>(queuedJobsList.size());
                for (auto &queuedJobsListMember : queuedJobsList)
                {
                    Aws::Iotjobs::JobExecutionSummary queuedJobsListValMember;
                    queuedJobsListValMember = queuedJobsListMember.AsObject();
                    val.QueuedJobs->push_back(std::move(queuedJobsListValMember));
                }
            }

            if (doc.ValueExists("timestamp"))
            {
                val.Timestamp = doc.GetDouble("timestamp");
            }

            if (doc.ValueExists("inProgressJobs"))
            {
                auto inProgressJobsList = doc.GetArray("inProgressJobs");
                val.InProgressJobs = Aws::Crt::Vector<Aws::Iotjobs::JobExecutionSummary>(inProgressJobsList.size());
                for (auto &inProgressJobsListMember : inProgressJobsList)
                {
                    Aws::Iotjobs::JobExecutionSummary inProgressJobsListValMember;
                    inProgressJobsListValMember = inProgressJobsListMember.AsObject();
                    val.InProgressJobs->push_back(std::move(inProgressJobsListValMember));
                }
            }
        }

        void GetPendingJobExecutionsResponse::SerializeToObject(Aws::Crt::JsonObject &object) const
        {
            (void)object;

            if (ClientToken)
            {
                object.WithString("clientToken", *ClientToken);
            }

            if (QueuedJobs)
            {
                Aws::Crt::Vector<Aws::Crt::JsonObject> queuedJobsList(QueuedJobs->size());
                for (auto &queuedJobsListMember : *QueuedJobs)
                {
                    Aws::Crt::JsonObject queuedJobsListValMember;
                    Aws::Crt::JsonObject jsonObject;
                    queuedJobsListMember.SerializeToObject(jsonObject);
                    queuedJobsListValMember.AsObject(std::move(jsonObject));
                    queuedJobsList.push_back(queuedJobsListValMember);
                }
                object.WithArray("queuedJobs", std::move(queuedJobsList));
            }

            if (Timestamp)
            {
                object.WithDouble("timestamp", Timestamp->SecondsWithMSPrecision());
            }

            if (InProgressJobs)
            {
                Aws::Crt::Vector<Aws::Crt::JsonObject> inProgressJobsList(InProgressJobs->size());
                for (auto &inProgressJobsListMember : *InProgressJobs)
                {
                    Aws::Crt::JsonObject inProgressJobsListValMember;
                    Aws::Crt::JsonObject jsonObject;
                    inProgressJobsListMember.SerializeToObject(jsonObject);
                    inProgressJobsListValMember.AsObject(std::move(jsonObject));
                    inProgressJobsList.push_back(inProgressJobsListValMember);
                }
                object.WithArray("inProgressJobs", std::move(inProgressJobsList));
            }
        }

        GetPendingJobExecutionsResponse::GetPendingJobExecutionsResponse(const Crt::JsonView &doc)
        {
            LoadFromObject(*this, doc);
        }

        GetPendingJobExecutionsResponse &GetPendingJobExecutionsResponse::operator=(const Crt::JsonView &doc)
        {
            *this = GetPendingJobExecutionsResponse(doc);
            return *this;
        }

    } // namespace Iotjobs
} // namespace Aws
